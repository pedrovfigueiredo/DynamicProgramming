//
//  Knapsack.hpp
//  DynamicProgramming
//
//  Created by Pedro Figueirêdo on 12/10/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#ifndef Knapsack_hpp
#define Knapsack_hpp
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>

class Knapsack
{
public:
    
    struct Object{
        Object(int weight,int value){weight_ = weight; value_ = value;}
        int weight_;
        int value_;
    };
    
    Knapsack(int capacity, std::vector<Object*>& objects);
    Knapsack(const std::string& fileName);
    ~Knapsack();
    
    void solveKnapsackProblem(std::list<std::size_t>& solutionObjects, int& solutionValue);
    
private:
    
    void selectSolutionObjects(std::list<std::size_t>& solutionObjects);
    
    int capacity_;
    std::vector<Object*> objects_;
    std::vector< std::vector<int> > solutionsMatrix_;
};

#endif /* Knapsack_hpp */
