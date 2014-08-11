//
//  AugustChallenge2.cpp
//  TestApps
//
//  Created by Praveen S on 8/10/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "AugustChallenge2.h"
#include <iostream>
using namespace std;
#include<vector>

long long lcm(long long n1, long long n2) {
    long long temp1=n1;
    long long temp2=n2;
    while(temp1!=temp2)
    {
        if(temp1>temp2)
            temp1-=temp2;
        else
            temp2-=temp1;
    }
    return (n1*n2/temp1);
}

int mainAC2()
{
    long long testcases = 0;
    cin >> testcases;
    while(testcases > 0){
    	long long A, B, N;
    	cin >> A;
    	cin >> B;
    	cin >> N;
    	long long lcmAB;
    	if(A>B){
    		lcmAB = lcm(A,B);
    	} else {
    		lcmAB = lcm(B,A);
    	}
    	long long numA = (lcmAB/A) - 1;
    	long long numB = (lcmAB/B) - 1;
    	long long duplicateIndex = numA + numB + 1;
        long long startAt = N / duplicateIndex;
        long long endAt = N % duplicateIndex;
        long long i = 1;
        long long j = 1;
        long long lastAdded = A;
        if(startAt == 0){
        	lastAdded = (A < B) ? A:B;
        	i = 1;
        	j = 1;
        } else {
        	lastAdded = lcmAB * startAt;
        	i = (lastAdded/A) +1 ;
        	j = (lastAdded/B) +1;
        }
        
        
        numA = i * A;
        numB = j * B;
        int count = 0;
        /*
         cout<<"Dupliccate Index : " << duplicateIndex << " " << " i = " << i << " j = " << j << endl;
         cout<<"Start at: " << startAt << " ";
         cout<<"End at: " << endAt << " ";
         cout<<"Last Added: " << lastAdded<< " ";
         cout<<"LCM : " << lcmAB << " " <<endl;*/
        
    	
    	while(count < endAt) {
            /*
             cout<<"Num A: " << numA << " ";
             cout<<"Num B: " << numB << " ";
             cout<<"Count: " << count << endl;
            */
            if (numA < numB) {
                lastAdded = numA;
                i++;
                numA = i * A;
            } else {
                lastAdded = numB;
                j++;
                numB = j * B;
            }
            count ++;
    		
    	}
    	cout << lastAdded << endl;
    	testcases --;
    }
    return 0;
}

