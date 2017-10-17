//
//  main.cpp
//  DynamicProgramming
//
//  Created by Pedro Figueirêdo on 12/10/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#include <iostream>
#include "Knapsack.hpp"

int main(int argc, const char * argv[]) {
    
    std::list<std::size_t> solutionObjects;
    int solutionValue;
    //const std::string fileName = "/Users/PedroFigueiredo/Google Drive/5 Período/Análise e Projeto de Algoritmos/Algoritmos APA/DynamicProgramming/Knapsack/Instances/mochila1000.txt";
    const std::string fileName = argv[1];
    
    Knapsack k(fileName);
    k.solveKnapsackProblem(solutionObjects, solutionValue);
    
    std::cout << "Solution Value: " << solutionValue << std::endl;
    std::cout << "Solution Objects: ";
    
    std::cout << solutionObjects.front();
    solutionObjects.pop_front();
    
    for(auto object : solutionObjects)
        std::cout << ", " << object;
    std::cout << std::endl;
    
    return 0;
}
