//
//  Marbles.cpp
//  TestApps
//
//  Created by Praveen S on 8/5/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "Marbles.h"
#include <iostream>
using namespace std;

long long findCombinations(int n, int m) {
    // Aim to find nCm = n!/(m!) * (n-m)!
    n--;
    m--;
    
    long long result = 1;
    if(m > n/2)
        m = n-m;
    for (int i = 0 ; i < m; i++) {
        result *= (n-i);
        result /= (i+1);
    }
    
    return result;
}

int main() {
	int tests;
	cin>>tests;
	int n,m;
	while(tests > 0){
		cin>>n>>m;
		cout << findCombinations(n,m)<< endl;
		tests--;
	}
}