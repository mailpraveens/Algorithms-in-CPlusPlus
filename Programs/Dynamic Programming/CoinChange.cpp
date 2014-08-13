//
//  CoinChange.cpp
//  TestApps
//
//  Created by Praveen S on 8/11/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "CoinChange.h"


int coinChangeProblem(int * denomination, int n, int changeToMake){
    int M[n+1];
    M[0] = 0;
    // M[i] gives min coins to make change i from given values
    for (int i = 0; i < changeToMake; i++) {
        M[i] = INT_MAX;
        int temp = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (denomination[j] <=  changeToMake) {
                //Use this coin
                int temp_amt = denomination[i - denomination[j]] + 1;
                if (temp_amt < temp ) {
                    
                }
            }
        }
    }
    
    return M[n];
}