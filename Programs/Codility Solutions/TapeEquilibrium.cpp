//
//  TapeEquilibrium.cpp
//  TestApps
//
//  Created by Praveen S on 8/23/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

using namespace std;
#include <vector>
#include <cstdlib>

int TapeEquilibrium(vector<int> &A) {
    // write your code in C++11
    vector <int> B;
    int min = 0;
    B.push_back(A[0]);
    min = A[0];
    int n = A.size();
    for(int i = 1 ; i < n ; i++ ){
        B.push_back(B[i-1] + A[i]);
    }
    for( int i = n - 1 ; i > 0  ; i-- ) {
        A[i-1] += A[i];
    }
    
    for( int i = 0 ; i < n  ; i++ ) {
        if(abs(B[i] - A[i+1]) < min) {
            min = abs(B[i] - A[i+1]);
        }
    }
    
    return min;
}