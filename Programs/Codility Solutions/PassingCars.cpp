//
//  PassingCars.cpp
//  TestApps
//
//  Created by Praveen S on 8/23/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//
using namespace std;
#include <vector>

int PassingCars(vector<int> &A) {
    // write your code in C++11
    int total = 0;
    int west = 0;
    for(int i = A.size() - 1 ; i >=0  ; i--) {
        if(A[i] == 0) {
            total += west;
        } else if(A[i]  == 1) {
            west++;
        }
    }
    return total;
}
