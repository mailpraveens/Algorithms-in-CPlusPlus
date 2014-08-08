//
//  MaxProductCut.cpp
//  TestApps
//
//  Created by Praveen S on 8/8/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "MaxProductCut.h"
using namespace std;

int max(int a, int b) { return (a > b)? a : b;}
int max(int a, int b, int c) { return max(a, max(b, c));}


int MaxProductCutRecursive(int n) {
    if (n == 0 || n == 1) return 0;
    
    int maxVal = 0;

    for (int i = 1; i < n; i++) {
        maxVal = max(maxVal ,i * (n-i) , MaxProductCutRecursive(n-i) * i);
    }
    return maxVal;
}

int MaxProductCutDP(int n) {
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 0;
    int maxVal = 0;
    
    for (int i = 1; i <= n; i++) {
        maxVal = 0;
        for (int j = 1; j <= i/2; j++) {
            maxVal = max(maxVal, j * (i-j) , dp[i-j] * j);
        }
        dp[i] = maxVal;
    }
    
    return dp[n];
}

int main() {
    cout<<"The Recursive solution is " << MaxProductCutRecursive(10)<< endl;
    cout<<"The Dynamic Programming solution is " << MaxProductCutDP(10)<< endl;
    return 0;
}
