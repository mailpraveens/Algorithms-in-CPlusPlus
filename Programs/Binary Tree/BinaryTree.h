//
//  BinaryTree.h
//  TestApps
//
//  Created by Praveen S on 8/7/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#ifndef __TestApps__BinaryTree__
#define __TestApps__BinaryTree__

#include <iostream>
typedef struct node_t node;

struct node_t{
    int data;
    node * left;
    node * right;
};



class BinaryTree{
private:
    BinaryTree();
    ~BinaryTree();
public:
    static bool isBST(node * root);
    static node * getParent(node * root, int data);
    static node * getNewNode(int data);
    static node * findLCA(node * root ,int node1, int node2);
    static int  findRangeSum(node * root, int min, int max);
    static bool hasPathSum(node * root, int sum);
    static void printAllPaths(node * root);
    static void allTraversals(node * root);
    static bool isBalanced(node * root);
    static int getHeight(node * root);
    static node * createBSTFromArray(int *arr, int n);
    static int createLevelOrderLinkedList(node * root);
    static int inOrderSuccesor(node * root, int data);
    static bool checkIfOneTreeExistsinOther(node * tree1, node * tree2);
};

#endif /* defined(__TestApps__BinaryTree__) */
