//
//  Graph.h
//  TestApps
//
//  Created by Praveen S on 7/19/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#ifndef __TestApps__Graph__
#define __TestApps__Graph__

#include<iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
    int V;
    list <int> * adj;
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
    
    
public:
    Graph(int V);
    void addEdge(int V, int w);
    void DFS();    // prints DFS traversal of the complete graph
    void BFS();
    bool checkIfBipartite();
    bool isSC(); // Is strongly connected
    bool isEularianCycle();
    Graph getTranspose();
    void topologicalSorting();
    void topologicalSortingUtil(int n, bool * visited, stack<int> &s);
    bool checkRouteExistsBetweenNodes(int s, int d);
    
};
#endif /* defined(__TestApps__Graph__) */
