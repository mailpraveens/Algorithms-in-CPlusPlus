

#include<iostream>
#include <list>
#include <array>
using namespace std;
#include "Graph.h"
#include "ArrayProblems.h"
#include "Marbles.h"
#include "BinaryTree.h"
#include "Strings.h"



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
    printDelimiter();
    cout<<"The Topological sort is as follows:"<<endl;
    g.topologicalSorting();

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

void testCombinationMarbles(){
    cout<<"10 10 " << findCombinations(10, 10) << endl;
    cout<<"30 7 " << findCombinations(30, 7) << endl;
    
    
}

void testBinaryTreeMethods(){
    node * root = BinaryTree::getNewNode(5);
    root->left = BinaryTree::getNewNode(3);
    root->right = BinaryTree::getNewNode(7);
    root->left->left = BinaryTree::getNewNode(2);
    root->left->right = BinaryTree::getNewNode(4);
    root->right->left = BinaryTree::getNewNode(6);
    root->right->right = BinaryTree::getNewNode(8);
    
    node * child = BinaryTree::getParent(root, 3);
    
    
    cout<<"Parent of the given node is : " <<child->data << endl;
    
    printDelimiter();
    
    if (BinaryTree::isBST(root)) {
        cout<<" Is a BST" << endl;
    } else {
        cout<<" Not a BST" << endl;
    }
    printDelimiter();
    
    node * lca = BinaryTree::findLCA(root, 8, 2);
    if (lca) {
        cout<<"LCA is : "<< lca->data <<endl;
    } else {
        cout<<" Not found "<<endl;
    }
    printDelimiter();
    cout<<"Range sum is ::"<< BinaryTree::findRangeSum(root, 8, 10) << endl;
    
    printDelimiter();
    cout<<"Has path sum is ::"<< BinaryTree::hasPathSum(root, 10) << endl;
    
    printDelimiter();
    cout<<"All Paths are:"<< endl;
    BinaryTree::printAllPaths(root);
    
    cout<<"All Traversals are:"<< endl;
    BinaryTree::allTraversals(root);
}

void testStringFunctions(){
    char str[] = "geeksforgeeks";
    cout << "The inplace removal of duplicates is :"<< removeDuplicates(str)<< endl;
    printDelimiter();
    cout << "The Excel Column Conversion is :"<< getExcelColumnName(1)<< endl;
    cout << "The Excel Column Conversion is :"<< getExcelColumnName(53)<< endl;
    cout << "The Excel Column Conversion is :"<< getExcelColumnName(705)<< endl;
    printDelimiter();
    countDecodings("1234");
    countDecodings("121");
    countDecodings("3456");
    countDecodings("9879");
    
    printDelimiter();
    cout<< " All permutations are :" <<endl;
    recPermute("", "abcd");
    printDelimiter();
    cout<< " All subsets are :" <<endl;
    string input = "abcd";
    allSubsets("", input);
    
    printDelimiter();
    int number[] = {8,4,6,2};
    allCombinationsOfKeyPad(number, 4);
    
}

int mainaaaa(int argc, const char * argv[])
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
    testCombinationMarbles();
    printDelimiter();
    testBinaryTreeMethods();
    printDelimiter();
    testStringFunctions();
    printDelimiter();
    return 0;
}

