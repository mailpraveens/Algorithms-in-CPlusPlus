//
//  LittleElephantAndBallsAgain.cpp
//  TestApps
//
//  Created by Praveen S on 8/8/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "LittleElephantAndBallsAgain.h"

int LittleElephantAndBallsAgain::getCharCount(char s){
    int count = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == s) {
            count++;
        }
    }
    return count;
}

int LittleElephantAndBallsAgain::getMaxContiguousCount(char s) {
    int count = 0;
    int maxSoFar = 0;
    
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == s) {
            count++;
        } else {
            if (count > maxSoFar) {
                maxSoFar = count;
            }
            count = 0;
        }
    }
    
    
    return maxSoFar;
}


int LittleElephantAndBallsAgain::getCount(){
    
    int countR = getCharCount('R');
    int countG = getCharCount('G');
    int countB = getCharCount('B');
    
    if ((!countR && !countB)) {
        return countG;
    } else if (!countG && !countB) {
        return countR;
    } else if(!countG && !countR) {
        return countB;
    }
    
    
    int maxR = getMaxContiguousCount('R');
    int maxG = getMaxContiguousCount('G');
    int maxB = getMaxContiguousCount('B');
    int overallMax = maxR;
    
    if (overallMax < maxG) {
        overallMax = maxG;
    }
    if (overallMax < maxB) {
        overallMax = maxB;
    }
    
    
    return (int)strlen(input) - overallMax;
    
}

/*
int main(){
	LittleElephantAndBallsAgain ele;
    ele.input = "RGGGGGBBB";
	std::cout << ele.getCount() << "\n";
}*/