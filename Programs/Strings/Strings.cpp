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
    