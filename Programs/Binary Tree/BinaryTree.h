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
};

#endif /* defined(__TestApps__BinaryTree__) */
