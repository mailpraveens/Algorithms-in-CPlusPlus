//
//  ArrayProblems.cpp
//  TestApps
//
//  Created by Praveen S on 7/21/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "ArrayProblems.h"
using namespace std;
#include <array>
/*
    Function to find a max subarray where no two elements are adjacent to each other
 */
int findMaxSubArrayNoAdjacent( int a[], int n){
    int excl_new;
    int inc = a[0];
    int exc = 0;
    for (int i = 1; i < n; i++) {
        // Max excluding i
        excl_new = ( inc > exc) ? inc : exc;
        
        // Max including i
        inc = exc + a[i];
        exc = excl_new;
    }
    return (inc > exc) ? inc : exc;
}

/*
    Find a triplet such that a[i] + a[j] + a[k] ==d
 */


int findTripletsFromArray(int a[], int n, int total) {
    int i,left , right;
    i = 0;
    left = 0;
    right = n-1;
    
    for (i = 0 ; i < n; i++) {
        left = i+1;
        right = n-1;
        while (left < right) {
            if( a[i] + a[left] + a[right] <= total) {
                cout<<a[i] << "+" << a[left] << "+" << a[right] << "<=" << total << endl;
                left++;
            } else {
                right--;
            }
            
        }
    }
    
    
    return 0;
}
