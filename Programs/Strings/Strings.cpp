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

    