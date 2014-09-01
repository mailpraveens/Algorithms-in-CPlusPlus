//
//  File.cpp
//  TestApps
//
//  Created by Praveen S on 9/1/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include <iostream>
using namespace std;

int SeptChallenge1()
{
    int testcases;
    cin >> testcases;
    while(testcases > 0) {
    	int count = 0;
    	int start , end;
    	int hops;
    	
    	cin >> start >> end >> hops;
    	if(hops > 0) {
            if(start % hops != 0) {
	    		start = ((start / hops) + 1) * hops ;
	    	}
            
	    	if(start < end) {
	    		count  = (end -  start ) / hops;
                if((end -  start ) % hops != 0) {
	    			count += 1;
	    		}
	    		if(end % hops  == 0){
	    			count += 1;
	    		}
	    	} else{
	    		
	    	}
    	}
    	
    	
    	
		
    	cout<< count << endl;
    	testcases--;
    }
    return 0;
}
