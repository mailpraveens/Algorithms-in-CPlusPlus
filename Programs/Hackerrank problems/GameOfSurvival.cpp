//
//  GameOfSurvival.cpp
//  TestApps
//
//  Created by Praveen S on 8/10/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "GameOfSurvival.h"
#include <iostream>
using namespace std;
#include <stdlib.h>     /* qsort */

int compare (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases > 0){
    	int n;
    	cin >> n;
        int anistrength[n];
        int swordPower[n];
    	for(int i = 0; i < n ; i++){
    		cin >> swordPower[i];
    	}
    	for(int i = 0; i < n ; i++){
    		cin >> anistrength[i];
    	}
    	qsort (anistrength, n, sizeof(int), compare);
        
    	qsort (swordPower, n, sizeof(int), compare);
    	int k=0;
    	for(k = 0; k < n; k++){
    		if(swordPower[k] < anistrength[k]) {
    			cout<<"NO"<<endl;
    			break;
    		}
    	}
    	if(k == n){
    		cout<<"YES"<<endl;
    	}
		testcases--;
    }
    return 0;
}