

#include<iostream>
#include <list>
#include <array>
using namespace std;
#include "Graph.h"
#include "ArrayProblems.h"



int modifyArray(int *arr, int size) {
    for (int i = 0 ; i < size; i++) {
        cout << arr[i] <<endl;
        arr[i] = i*i;
    }
    return 0;
}


int modifyArray(int **arr, int size) {
    for (int i = 0 ; i < size; i++) {
        cout << *arr[i] << endl;
    }
    return 0;
}

char  * addStrings(char * str1, char * str2) {
    char * returnString = (char *) malloc(strlen(str1) + strlen(str2)+1);
    strcpy(returnString, str1);
    strcpy(returnString+strlen(str1), str2);
    
    return returnString;
    
}

void printDelimiter(){
    cout<<endl;
    cout<<endl;
    for (int i =0 ; i < 15; i++) {
        cout<<" * - * ";
    }
    cout<<endl;
    cout<<endl;
    
}

void testGraph() {
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 7);
    g.addEdge(4, 8);
    g.addEdge(5, 3);
    g.addEdge(5, 6);
    g.addEdge(6, 5);
    g.addEdge(7, 4);
    g.addEdge(8, 4);
    cout << "Following is breadth First Traversal (starting from vertex 2) \n";
    g.BFS();
    printDelimiter();
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS();
    printDelimiter();
    cout << "Following is Check for Bipartiteness \n";
    g.checkIfBipartite();

}

void testMaxSubarrayNoAdjacent() {
    int arr[] = { 2,5,6,7,8};
    printf("%d",findMaxSubArrayNoAdjacent(arr, 5));
}


void testSumOf3ArrayIndexes(){
    int arr[] = { 2,5,6,7,8, 9, 10};
    findTripletsFromArray(arr, 7, 20);

}

void testOccurancesOfNumInSortedArray() {
    int myNums[] = {1,1,2,2,2,2,2,2,3,4,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,8,9};
    int endIndex = sizeof(myNums)/sizeof(int);
    cout<<"Occurance of 6 in Array is " << countOccurancesOfElementInSortedArray(myNums, 6, 0, endIndex);
}
int main(int argc, const char * argv[])
{
    printDelimiter();
    testGraph();
    printDelimiter();
    testMaxSubarrayNoAdjacent();
    printDelimiter();
    testSumOf3ArrayIndexes();
    printDelimiter();
    testOccurancesOfNumInSortedArray();
    printDelimiter();

    
        return 0;
}

