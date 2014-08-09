//
//  ArrayProblems.cpp
//  TestApps
//
//  Created by Praveen S on 7/21/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "ArrayProblems.h"
using namespace std;
#include <array>
/*
    Function to find a max subarray where no two elements are adjacent to each other
 */
int findMaxSubArrayNoAdjacent( int a[], int n){
    int excl_new;
    int inc = a[0];
    int exc = 0;
    for (int i = 1; i < n; i++) {
        // Max excluding i
        excl_new = ( inc > exc) ? inc : exc;
        
        // Max including i
        inc = exc + a[i];
        exc = excl_new;
    }
    return (inc > exc) ? inc : exc;
}

/*
    Find a triplet such that a[i] + a[j] + a[k] ==d
 */


void findTripletsFromArray(int a[], int n, int total) {
    int i,left , right;
    i = 0;
    left = 0;
    right = n-1;
    
    for (i = 0 ; i < n; i++) {
        left = i+1;
        right = n-1;
        while (left < right) {
            if( a[i] + a[left] + a[right] <= total) {
                cout<<a[i] << "+" << a[left] << "+" << a[right] << "<=" << total << endl;
                left++;
            } else {
                right--;
            }
            
        }
    }
    return;
}

/*
    Find occurances of a num in an array, this will use a helper function similar to binary search
 */


int countOccurancesOfElementInSortedArray(int a[], int num, int startIndex, int endIndex) {
    
    if(startIndex > endIndex) {
        return 0;
    }
    
    if (a[startIndex] > num) {
        // The smallest in the set is greater than num, so num doesn't exist
        return 0;
    }
    
    if (a[endIndex] < num) {
        // The largest in the set is smaller than num, so num doesn't exist
        return 0;
    }
    
    int midIndex = (startIndex + endIndex) / 2;
    
    if (a[midIndex] == num) {
        return 1 + countOccurancesOfElementInSortedArray(a, num, startIndex, midIndex - 1) + countOccurancesOfElementInSortedArray(a, num, midIndex + 1 , endIndex);
    }
    else if(a[midIndex] > num) {
        //Search only left half
        countOccurancesOfElementInSortedArray(a, num, startIndex, midIndex-1);
    } else {
        countOccurancesOfElementInSortedArray(a, num, midIndex + 1, endIndex);
    }
    
    return 0;
}
// All possible values for key press combination
char hashtable[10] [5] = { "", "",  "abc" ,"def" , "ghi", "jkl","mno", "pqrs", "tuv", "wxyz" };
void allCombinationsOfKeyPadUtil( int * num, int current, int total, char * result) {
    if (current == total) {
        cout << result << endl;
        return;
    }
    for (int i = 0 ; i < strlen(hashtable[num[current]]); i++) {
        result[current] =  hashtable[num[current]] [i];
        allCombinationsOfKeyPadUtil(num, current + 1, total, result);
    }
}



void allCombinationsOfKeyPad(int *num, int n) {
    char  results[n+1];
    results[n] = '\0';
    allCombinationsOfKeyPadUtil(num, 0, n, results);
}


