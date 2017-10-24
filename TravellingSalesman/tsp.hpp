//
//  tsp.hpp
//  TravellingSalesman
//
//  Created by Pedro Figueirêdo on 19/10/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#ifndef tsp_hpp
#define tsp_hpp

#define nBits 200

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "compare_structs.h"

struct solutionData{
    int currCity;
    std::string combination;
};

class TSP
{
public:
    typedef std::bitset<nBits> Combination;
    typedef std::vector<std::string> Combinations;
    
    TSP(const std::string fileName);
    ~TSP();
    
    void solve(int& solutionCost, std::vector<int>& solutionPath);
    
private:
    int getMinimum(std::vector<int>&v, int currRow, std::unordered_map<std::string, solutionData*>& solution);
    void buildAllCombinations();
    void computeSolutionPath(std::unordered_map<std::string, solutionData*>& solution, std::vector<int>& solutionPath);
    void combinationToVector(const std::string& in, std::vector<int>& out);
    void vectorToCombination(const std::vector<int>& in, std::string& out, const unsigned int& n);

    std::vector< std::map< std::string, int, compareSet > > dynamicMatrix;
    std::vector< std::vector<int> > adjacentMatrix;
};

#endif /* tsp_hpp */
