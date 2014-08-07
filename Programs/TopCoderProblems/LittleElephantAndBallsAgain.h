//
//  LittleElephantAndBallsAgain.h
//  TestApps
//
//  Created by Praveen S on 8/8/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#ifndef __TestApps__LittleElephantAndBallsAgain__
#define __TestApps__LittleElephantAndBallsAgain__

#include <iostream>

class LittleElephantAndBallsAgain {
public:
    int getCount();
    char * input;
private:
    int getCharCount(char s);
    int getMaxContiguousCount(char s);
};

#endif /* defined(__TestApps__LittleElephantAndBallsAgain__) */
