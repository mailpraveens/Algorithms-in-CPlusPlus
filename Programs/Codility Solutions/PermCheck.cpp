//
//  PermCheck.cpp
//  TestApps
//
//  Created by Praveen S on 8/23/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include <vector>
#include <cstdlib>



int PermCheck(std::vector<int> &A) {
    // write your code in C++11
    bool B[A.size()];
    
    for(int i = 0 ; i < A.size() ; i++ ) {
        B[i] =  false;
    }
    for(int i = 0 ; i < A.size() ; i++ ) {
        B[A[i]-1] = true;
    }
    for(int i = 0 ; i < A.size() ; i++ ) {
        if(B[i] == false)
            return 0;
    }
    return 1;
}