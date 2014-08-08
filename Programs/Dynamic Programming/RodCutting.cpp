//
//  RodCutting.cpp
//  TestApps
//
//  Created by Praveen S on 8/8/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "RodCutting.h"
using namespace std;

int max(int a, int b) { return (a > b)? a : b;}

int rodCuttingRecursive(vector <int> & price, int n) {
    if (n<=0) {
        return 0.0;
    }
    int max_val = -1;
    for (int i = 0; i < n; i++ ) {
        int tmp = price[i] + rodCuttingRecursive(price, n-i-1);
        if (tmp > max_val) {
            max_val = tmp;
        }
    }
    return max_val;
}


int rodCuttingDynamicProg(vector<int> & price , int n) {
    int dp[n+1];
    dp[0] = 0;
    int max_val ;
    
    for (int i = 1; i <= n; i++) {
        max_val = -1;
        for (int j = 0; j < i ; j++) {
            max_val = max(max_val, price[j] + dp[i-j-1]);
        }
        dp[i] = max_val;
        cout<< "Price at cutting at "<< i << "is :" << dp[i] <<endl;
    }
    
    return dp[n];
}


int main3() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<"The Recursive solution is " << rodCuttingRecursive(price, 8)<< endl;
    cout<<"The Dynamic Programming solution is " << rodCuttingDynamicProg(price, 8)<< endl;
    return 0;
}
