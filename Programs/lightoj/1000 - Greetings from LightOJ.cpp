//
//  1000 - Greetings from LightOJ.cpp
//  TestApps
//
//  Created by Praveen S on 8/18/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include<iostream>
using namespace std;

int Greetings() {
	int tests;
	cin>>tests;
	int n,m,i = 1;
	while(tests > 0){
		cin>>n>>m;
		cout<<"Case " << i++ <<": " <<m+n <<endl;
		tests--;
	}
    return 0;
}