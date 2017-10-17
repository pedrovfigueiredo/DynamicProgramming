//
//  Knapsack.cpp
//  DynamicProgramming
//
//  Created by Pedro Figueirêdo on 12/10/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#include "Knapsack.hpp"

Knapsack::Knapsack(int capacity, std::vector<Object*>& objects):
capacity_(capacity), objects_(objects)
{}

Knapsack::Knapsack(const std::string& fileName){
    int aux,p,v;
    std::ifstream file(fileName);
    
    file >> aux;
    objects_.reserve(aux);
    
    file >> aux;
    capacity_ = aux;
    
    while(file >> p >> v)
        objects_.push_back(new Knapsack::Object(p,v));
    
    file.close();
}

Knapsack::~Knapsack(){}

void Knapsack::solveKnapsackProblem(std::list<std::size_t>& solutionObjects, int& solutionValue){
    
    // Resize solutionsMatrix to have (nObjects + 1) rows and (capacity + 1) columns
    solutionsMatrix_.resize(objects_.size() + 1,std::vector<int>(capacity_ + 1));
    
    std::size_t nRows = solutionsMatrix_.size();
    std::size_t nColumns = solutionsMatrix_.front().size();
    
    // First row and column of the solution matrix is always zero
    std::fill(solutionsMatrix_.front().begin(), solutionsMatrix_.front().end(), 0);
    for(auto row : solutionsMatrix_)
        row.front() = 0;
    
    for (std::size_t i = 1; i < nRows; i++) {
        for (std::size_t j = 1; j < nColumns; j++) {
            
            // Check if it's possible to include this object with the current weight (column)
            if(this->objects_[i - 1]->weight_ <= j){
                // Check if it's better to include the object or to leave it out the knapsack
                solutionsMatrix_[i][j] = std::max(objects_[i - 1]->value_ + solutionsMatrix_[i - 1][j - objects_[i - 1]->weight_], solutionsMatrix_[i - 1][j]);
            }else{
                // Copies last element's value for current weight (column)
                solutionsMatrix_[i][j] = solutionsMatrix_[i - 1][j];
            }
        }
    }
    
    selectSolutionObjects(solutionObjects);
    
    // Solution Value will be at the intersection of the last row and column of solutionMatrix
    solutionValue = (solutionsMatrix_.back()).back();
}

void Knapsack::selectSolutionObjects(std::list<std::size_t>& solutionObjects){
    std::size_t j = solutionsMatrix_.front().size() - 1;
    
    for(std::size_t i = solutionsMatrix_.size() - 1; i > 0; i--){
        if(solutionsMatrix_[i - 1][j] != solutionsMatrix_[i][j]){
            solutionObjects.push_front(i);
            j -= objects_[i - 1]->weight_;
        }
    }
}
