//
//  MultTables.cpp
//  TestApps
//
//  Created by Praveen S on 8/25/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int MultTables() {
    
    cout << resetiosflags(ios::left);

    for (int j = 1; j <= 12; j++) {
        for (int i = 1; i <= 12; i++) {
            cout<< setw(4) << i * j;
        }
        cout<<endl;
    }
}