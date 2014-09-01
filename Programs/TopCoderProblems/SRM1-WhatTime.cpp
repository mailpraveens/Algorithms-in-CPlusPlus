//
//  SRM1-WhatTime.cpp
//  TestApps
//
//  Created by Praveen S on 8/25/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Time {
public:
	string whatTime(int);
};

string Time::whatTime(int seconds) {
	long S = seconds % 60;
	long M =  (seconds / 60) % 60;
	long H = ((seconds / 60) /60);
	return to_string(H) + ":" + to_string(M) + ":"+ to_string(S);
}

