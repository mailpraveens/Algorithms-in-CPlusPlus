//
//  BinaryTree.cpp
//  TestApps
//
//  Created by Praveen S on 8/7/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "BinaryTree.h"
using namespace std;
#include <queue>

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

node * BinaryTree::findLCA(node * root ,int node1, int node2) {
    if (!root) {
        return NULL;
    }
    if (node1 == root->data) {
        return root;
    }
    if( node2 ==  root->data ){
        return root;
    }
    
    node * lh = findLCA(root->left, node1, node2);
    node * rh = findLCA(root->right, node1, node2);
    
    if (lh && rh) {
        return root;
    }
    
    return (lh != NULL)?lh:rh;
}

int BinaryTree::findRangeSum(node * root, int min, int max) {
    if (!root) {
        return 0;
    }
    int value = 0;
    if (root->data >= min && root->data <= max) {
        value += root->data;
    }
    value += findRangeSum(root->left, min, max);
    value += findRangeSum(root->right, min, max);
    
    return value;
}


bool BinaryTree::hasPathSum(node * root, int sum) {
    if (!root) {
        return (sum == 0);
    }
   return hasPathSum(root->left, sum-root->data) || hasPathSum(root->right, sum-root->data);
    
}

void printAllPathsRecursive(node * root, int * paths, int pathLen) {
    if (!root) {
        return;
    }
    paths[pathLen] = root->data;
    pathLen++;
    if (root->left == NULL && root->right == NULL) {
        for (int i=0 ; i < pathLen; i++) {
            cout << paths[i] << " ";
        }
        cout<<endl;
        return;
    }
    printAllPathsRecursive(root->left, paths, pathLen);
    printAllPathsRecursive(root->right, paths, pathLen);
    
}

void BinaryTree::printAllPaths(node * root){
    int paths[1000];
    printAllPathsRecursive(root, paths, 0);
    
}

void inOrder(node* root) {
    if(!root) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    
}

void preOrder(node * root){
    if (!root) {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    
}

void postOrder(node * root) {
    if (!root) {
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrderTraversal(node * root) {
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node * node = q.front();
        cout<< node->data << " ";
        q.pop();
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
}

void BinaryTree::allTraversals(node * root) {
    cout<<"Inoder:" << endl;
    inOrder(root);
    cout<<endl <<"PostOrder:" << endl;
    postOrder(root);
    cout<<endl<<"PreOrder:" << endl;
    preOrder(root);
    cout<<endl<<"PreOrder:" << endl;
    levelOrderTraversal(root);
}



