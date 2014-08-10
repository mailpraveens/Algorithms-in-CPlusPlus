//
//  AugustChallenge1.cpp
//  TestApps
//
//  Created by Praveen S on 8/10/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "AugustChallenge1.h"
#include <iostream>
using namespace std;
#include <stdlib.h>     /* qsort */

int compare (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main4()
{
    int testcases = 0;
    cin >> testcases;
    while(testcases > 0) {
   		int n;
   		cin >> n;
   		int a[n];
   		for(int i = 0; i < n; i++){
   			cin >> a[i];
   		}
   		qsort(a, n, sizeof(int), compare);
   		
   		int i = 0;
   		int j = i;
   		int total = n;
   		for( i = 0 ; i < n-1 ;  i++){
   			if(a[i] < a[i+1]){
   				total = total - 1;
   			}
   		}
   		cout << total << endl;
   		
        testcases--;
    }
    return 0;
}

