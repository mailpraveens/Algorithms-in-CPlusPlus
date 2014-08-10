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

int checkHeight( node * root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) {
        return -1;
    }
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) {
        return -1;
    }
    int heightDiff = leftHeight - rightHeight;
    if (abs(heightDiff) > 1) {
        return -1;
    } else {
        return std::max(leftHeight, rightHeight) + 1;
    }
    
}


bool BinaryTree::isBalanced(node * root) {
    if (checkHeight(root) == -1) {
        return false;
    } else{
        return true;
    }
}

node * createBSTFromArrayHelper(int * arr, int low, int high) {
    if (high < low) {
        return NULL;
    }
    int mid = (low + high )/ 2;
    node * node = BinaryTree::getNewNode(arr[mid]);
    node->left = createBSTFromArrayHelper(arr, low, mid-1);
    node->right = createBSTFromArrayHelper(arr, mid+1, high);
    
    return node;
}

node * BinaryTree::createBSTFromArray(int * arr, int n) {    
    return createBSTFromArrayHelper(arr, 0, n-1);
}

node * findNodeInTree(node * root, int data){
    if (!root) {
        return NULL;
    }
    if (root->data == data) {
        return root;
    }
    node * left = findNodeInTree(root->left, data);
    if (!left) {
        return findNodeInTree(root->right, data);
    }
    return NULL;
}

int BinaryTree::inOrderSuccesor(node * root, int data) {
    node * curr = findNodeInTree(root, data);
    
    if (curr->right) {
        // Find left most node in this
    } else{
        node * successor = NULL;
        node * ancestor = root;
        while (ancestor != curr) {
            if (curr->data  < ancestor ->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
    }
    
    return 0;
}

bool matchTree(node * tree1, node * tree2){
    if (tree1 == NULL && tree2 == NULL) {
        return true;
    }
    if (tree1 == NULL || tree2 == NULL) {
        return false;
    }
    if (tree1->data == tree2->data) {
        return matchTree(tree1->left, tree2->left) && matchTree(tree1->left, tree2->left);
    }
    return false;
}

bool findSubtree(node * tree1, node * tree2) {
    if (tree1 == NULL) {
        return false;
    }
    if (tree1->data == tree2->data) {
        return matchTree(tree1, tree2);
    }
    return matchTree(tree1->left, tree2) || matchTree(tree1->right, tree2);
}

bool BinaryTree::checkIfOneTreeExistsinOther(node * tree1, node * tree2) {
    if (tree2 == NULL) {
        return true; // Null tree is also a subtree
    }
    
    
    return false;
}

// Idea is to get max from left, and right and add to root
// Also check if left is max than right, and get overall max
int findOverallMax(node * root, int * res){
    if (!root) {
        return 0;
    }
    
    int leftMax = findOverallMax(root->left, res);
    int rightMax = findOverallMax(root->right, res);
    int currMax = std::max((leftMax + rightMax + root->data), std::max(leftMax, rightMax));
    if (*res < currMax) {
        *res = currMax;
    }
    
    return max(leftMax, rightMax) + root->data;
}

int BinaryTree::findMaxSumPath(node * root){
    int res = 0;
    findOverallMax(root, &res);
    return res;
    
}

void findHorizontalDistance(node * root, int *left, int * right, int hd){
    if (root == NULL) {
        return;
    }
    if (*left>hd) {
        *left = hd;
    }
    if (*right < hd) {
        *right = hd;
    }
    
    findHorizontalDistance(root->left, left, right, hd-1);
    findHorizontalDistance(root->right, left, right, hd+1);
}

void printAtLevel(node * root, int level, int hd){
    if (!root) {
        return;
    }
    if (level == hd) {
        cout<< root-> data;
    }
    printAtLevel(root->left, level, hd-1);
    printAtLevel(root->right, level, hd+1);
    
}

void BinaryTree::printTreeVertical(node * root){
    int leftMax = 0;
    int rightMax = 0;
    int horizontalDist = 0;
    findHorizontalDistance(root, &leftMax, &rightMax,  horizontalDist);
    // Now using left and right max print the values
    for (int i = leftMax; i < rightMax; i++) {
        printAtLevel(root, i, 0);
    }
    
}


