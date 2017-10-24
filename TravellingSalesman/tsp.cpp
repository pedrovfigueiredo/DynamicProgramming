//
//  tsp.cpp
//  TravellingSalesman
//
//  Created by Pedro Figueirêdo on 19/10/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#include "tsp.hpp"

TSP::TSP(const std::string fileName){
    std::ifstream file(fileName);
    
    int n;
    
    file >> n;
    
    adjacentMatrix.resize(n);
    for(auto& row: adjacentMatrix)
        row.resize(n);
    
    for(auto& row: adjacentMatrix)
        for(auto& column: row)
            file >> column;
    
    file.close();    
}

TSP::~TSP(){}

void TSP::solve(int& solutionCost, std::vector<int>& solutionPath){
    buildAllCombinations();
    int nVertices = (int)adjacentMatrix.size();
    std::string auxS;
    std::vector<int> auxV;
    std::unordered_map<std::string, solutionData*> solution;
    
    // empty set column
    for (int i = 1; i < nVertices; i++){
        dynamicMatrix[i][std::string( nVertices - 1 ,'0')] = adjacentMatrix[i][0];
    }
    
    // Multiple elements until before last column
    for (auto it = ++(dynamicMatrix[0].begin()); it != dynamicMatrix[0].end(); ++it){
        for (int i = 1; i < nVertices; i++){
            combinationToVector(it->first, auxV);
            
            // If row is not present in combination
            if ( std::find(auxV.begin(), auxV.end(), i) == auxV.end() )
                dynamicMatrix[i][it->first] = getMinimum(auxV, i, solution);
            
        }
    }
    
    // Compute last column
    auto it = --(dynamicMatrix[0].end());
    combinationToVector(it->first, auxV);
    solutionCost = getMinimum(auxV, 0, solution);
    dynamicMatrix[0][it->first] = solutionCost;
    
    // Compute solution path
    computeSolutionPath(solution, solutionPath);
}

int TSP::getMinimum(std::vector<int>&v, int currRow, std::unordered_map<std::string, solutionData*>& solution){
    // 1 element
    if (v.size() == 1)
        // dij + g(j,vazio)
        return adjacentMatrix[currRow][v[0]] + dynamicMatrix[v[0]][std::string( adjacentMatrix.size() - 1 ,'0')];
    
    // 2 or more
    std::string combination, vCombination;
    std::size_t vSize = v.size();
    std::size_t nVertices = adjacentMatrix.size();
    std::vector<int> auxV = v;
    int minCost = std::numeric_limits<int>::max();
    vectorToCombination(v, vCombination, (int)nVertices - 1);
    solution[vCombination] = new solutionData;
        
    
    for (int i = 0; i < vSize; i++) {
        int aux = auxV[i];
        auxV.erase(auxV.begin() + i);
        vectorToCombination(auxV, combination, (int)nVertices - 1);
        int currCost = adjacentMatrix[currRow][aux] + dynamicMatrix[aux][combination];
        if (currCost < minCost){
            minCost = currCost;
            solution[vCombination]->combination = combination;
            solution[vCombination]->currCity = aux;
        }
        
        auxV = v;
    }
    return minCost;
}

void TSP::computeSolutionPath(std::unordered_map<std::string, solutionData*>& solution, std::vector<int>& solutionPath){
    std::string column = (--(dynamicMatrix[0].end()))->first;
    std::vector<int> auxV;
    solutionPath.push_back(1);
    
    while(true){
        solutionPath.push_back(solution[column]->currCity + 1);
        combinationToVector(solution[column]->combination, auxV);
        if (auxV.size() == 1)
            break;
        
        column = solution[column]->combination;
    }
    
    solutionPath.push_back(auxV[0] + 1);
    solutionPath.push_back(1);
}

template <std::size_t N>
bool increase(std::bitset<N>& bs, std::size_t n)
{
    for (std::size_t i = 0; i != n; ++i) {
        if (bs.flip(i).test(i) == true) {
            return true;
        }
    }
    return false; // overflow
}

void TSP::buildAllCombinations(){
    const std::size_t nVertices = adjacentMatrix.size();
    Combination aux;
    std::map< std::string, int, compareSet > m;
    
    do {
        std::string str = aux.to_string();
        str.erase(str.begin(), str.begin() + (aux.size() -  nVertices + 1));
        m[str] = 0;
    } while (increase(aux, nVertices - 1));
        
    this->dynamicMatrix.reserve(nVertices);
    for (std::size_t i = 0; i < nVertices; i++)
        this->dynamicMatrix.push_back(m);
}

void TSP::combinationToVector(const std::string& in, std::vector<int>& out){
    out.clear();
    for (int i = 0; i < in.size(); i++)
        if (in[i] == '1')
            out.push_back(i + 1);
}

void TSP::vectorToCombination(const std::vector<int>& in, std::string& out, const unsigned int& n){
    out = std::string(n,'0');
    for(auto i : in)
        out[i - 1] = '1';
}
