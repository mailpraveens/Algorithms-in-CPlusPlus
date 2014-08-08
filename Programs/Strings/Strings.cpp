//
//  Strings.cpp
//  TestApps
//
//  Created by Praveen S on 8/8/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "Strings.h"
using namespace std;
#include <string>
#include <cstring>


char * removeDuplicates(char * str) {
    int hash[256]  = {0};
    int input_index = 0;
    int output_index = 0;
    while (*(str + input_index)) {
        char temp = *(str + input_index);
        if (hash[temp] == 0) {
            hash[temp] = 1;
            *(str + output_index) = *(str + input_index);
            output_index++;
        }
        input_index++;
    }
    *(str + output_index ) = '\0';
    return str;
}


char * strrev(char * str) {
    int end = (int)strlen(str) -1;
    int start=0;
    while (start < end) {
        char temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;
        start++;
        end--;
    }
    return str;
}
// Get remainder by 26, if equals 0 then add 'Z' else add
// remainder + 'A' to char string

char * getExcelColumnName( int num){
    
    char str[1000];
    int i =0;
    while (num > 0) {
        int rem = num % 26;
        if (rem == 0) {
            str[i] = 'Z';
            num = ( num / 26 ) - 1;

        } else {
            str[i] = (rem - 1) + 'A';
            num = num / 26;
        }
        i++;
    }
    
    str[i] = '\0';
    cout<< strrev(str) << endl;
    return ":";
}

/*Program to find the number of decodings of a particular sequence
  1234 --> can be decoded into 12, 3,4 as alphabet numbers
 or 1,23,4 or 1,2,3,4 -- Total 3
 */

// Dynamic programming
void countDecodings( const char * input) {
    int n = (int)strlen(input);
    int count[n+1];
    count[0] = 1; //Null String
    count[1] = 1;// The given number is the only sequence
    for (int i = 2 ; i <= n ; i++) {
        count[i] = 0;
        //Check if last number is 0, it doesnt add to the count
        if (input[i-1] > '0') {
            count[i] = count[i-1];
        }
        // Now check if i-2 and i-1 is between 2 and 7 then add to count
        if (input[i-2] < '2' || (input[i-2] == '2' && input[i-1] < '7')) {
            count[i] += count[i-2];
        }
    }
    cout<<"Total decodings of "<< input <<" are : "<< count[n]<< endl;
}

/*
 Check if given string is a rotation of a palindrome
 
 */
    