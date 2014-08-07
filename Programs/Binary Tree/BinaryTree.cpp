//
//  BinaryTree.cpp
//  TestApps
//
//  Created by Praveen S on 8/7/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree(){
    cout<< " Constructing a Binary Tree "<<endl;
}

BinaryTree::~BinaryTree(){
    cout << "Destructing a Binary Tree" << endl;
}

bool BinaryTree::isBST(node * root) {
    static node * prev = NULL;
    if (!root) {
        return true;
    }
    if(!isBST(root->left)){
        return false;
    }
    if (prev != NULL && prev->data >=  root->data) {
        return false;
    }
    prev = root;
    return isBST(root->right);
}

node *  BinaryTree::getParent(node * root, int data) {
    if(!root){
        return NULL;
    }
    if (root->left && root->left->data == data) {
        return root;
    }
    if (root->right && root->right->data == data) {
        return root;
    }
    node * lh = getParent(root->left,data);
    node * rh = getParent(root->right, data);
    
    return (lh!=NULL) ? lh: rh;
}


node * BinaryTree::getNewNode(int data) {
    node * newNode =(node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

