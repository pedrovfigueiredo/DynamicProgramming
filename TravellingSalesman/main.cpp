//
//  main.cpp
//  TravellingSalesman
//
//  Created by Pedro Figueirêdo on 18/10/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <chrono>
#include "tsp.hpp"

int main(int argc, const char * argv[]) {
    const std::string fileName = argv[1];
    //const std::string fileName = "/Users/PedroFigueiredo/Google Drive/5 Período/Análise e Projeto de Algoritmos/Algoritmos APA/DynamicProgramming/TravellingSalesman/Instances/prova.txt";
    std::vector<int> solutionPath;
    int solution;
    
    TSP tsp(fileName);
    
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    tsp.solve(solution,solutionPath);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    
    std::cout << "Solution:" << std::endl;
    std::cout << "\tCost: " << solution << std::endl;
    std::cout << "\tPath: ";
    for (auto i : solutionPath)
        std::cout << i << " ";
    std::cout <<  std::endl;
    std::cout << "Elapsed time: " << duration << " ms" <<std::endl;
    return 0;
}
