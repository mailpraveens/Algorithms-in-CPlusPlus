//
//  1001 - Opposite Task.cpp
//  TestApps
//
//  Created by Praveen S on 8/18/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include<iostream>
#include <stdlib.h>     /* srand, rand */
using namespace std;

int Opposite() {
	int tests;
	cin>>tests;
	long n,m;
	while(tests > 0) {
		cin >> m;
        if(m != 0){
            n = ( rand() % m );
            if (n > 10 || (m-n) > 10) {
                n = 10;
            }
        } else{
            n = 0;
        }
		cout<< n  << " " << m-n << endl;
		tests--;
	}
    return 0;
}