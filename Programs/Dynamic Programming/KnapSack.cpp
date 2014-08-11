//
//  KnapSack.cpp
//  TestApps
//
//  Created by Praveen S on 8/11/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "KnapSack.h"
using namespace std;
#include <vector>

/*
 Let M[i][j] be optimal value for knap sack with i items and j knapsack, then i varies from 0 to n
 j varies from 0 to C, capacity of knapsack.
 Either you use ith item or you dont use ith item
 So 
 
 M[i][j] = max { M[i-1][j], M[i-1][j-weight[i]] + weight[i]}
 
 */

int findKnapsack(int * values, int * weight, int n, int C){
    int M[n+1][C+1];
    
   /* for (int i = 0; i < n; i++) {
        M[i][0] = 0;
    }
    for (int i = 0; i < C; i++) {
        M[0][i] = 0;
    }*/
    for (int i = 0 ; i <= n ; i++ ) {
        for (int j = 0 ; j <= C ; j++) {
            if (i == 0 || j == 0) {
                M[i][j] = 0;
                continue;
            }
            
            if (weight[i-1] > j) {
                M[i][j] = M[i-1][j];
                cout << "M["<<i<<"]["<<j<<"] = " << M[i][j] << endl;
            } else{
                M[i][j] = M[i-1][j];
                if ( (M[i-1][j - weight[i-1]] + values[i-1]) > M[i][j]) {
                    M[i][j] = M[i-1][j-weight[i-1]] + values[i-1];
                }
                cout<< "M["<<i<<"]["<<j<<"] = " << M[i][j] << endl;
                
            }

            
            
        }
    }
    
    return M[n][C];
}

int mainKP() {
    int value[6] = {3,6,7,9,11,18};
    int weight[6] = {1,2,3,5,6,8};
    vector<int> pos;
    int w = findKnapsack(value, weight, 6, 5);
    cout << w << endl;
    return 0;  
}

