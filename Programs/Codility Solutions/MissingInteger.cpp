//
//  MissingInteger.cpp
//  TestApps
//
//  Created by Praveen S on 8/23/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include <vector>
#include <cstdlib>

int MissingInteger(std::vector<int> &A) {
    // write your code in C++11
    // write your code in C++11
    std::vector <bool> B;
    
    for(int i = 0 ; i < A.size() ; i++ ) {
        B.push_back(false);
    }
    for(int i = 0 ; i < A.size() ; i++ ) {
        B[A[i]-1] = true;
    }
    for(int i = 0 ; i < A.size() ; i++ ) {
        if(B[i] == false)
            return i+1;
    }
    return 0;
    
}