//
//  Graph.cpp
//  TestApps
//
//  Created by Praveen S on 7/19/14.
//  Copyright (c) 2014 Praveen S. All rights reserved.
//

#include "Graph.h"
using namespace std;
#include <queue>
#include <stack>


Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int V, int w) {
    this->adj[V].push_back(w); // push back to add to the linked list
}

void Graph::DFSUtil(int v , bool visited[]) {
    visited[v] = true;
    cout << v << " ";
    
    list<int>:: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
}

void Graph::DFS(){
    
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            DFSUtil(i, visited);
    
}

// To implement
void Graph::BFS(){
    queue <int> myQueue;
    bool * visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    if (visited[0] == false) {
        
        myQueue.push(0);
        visited[0] = true;
        while (!myQueue.empty()) {
            list<int>::iterator i;
            int node = myQueue.front();
            for (i = adj[node].begin(); i != adj[node].end(); i++) {
                if (!visited[*i]) {
                    cout << *i <<endl;
                    visited[*i] = true;
                    myQueue.push(*i);
                }

            }
            myQueue.pop();
        }
    }   
}

bool Graph::checkIfBipartite() {
    int *color = new int[V];
    for (int i= 0; i < V; i++) {
        color[i] = -1;
    }
    bool * visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    queue <int> myQueue;
    
    if (visited[0] == false) {
        myQueue.push(0); // Push the inital vertice
        visited[0] = true;
        color[0] = 1;
        while (!myQueue.empty()) {
            list<int>:: iterator it;
            int node = myQueue.front();
            myQueue.pop();
            for (it = adj[node].begin(); it != adj[node].end(); it++) {
                if (!visited[*it] && color[*it] == -1) {
                    color[*it] = abs(1 - color[node]);
                    visited[*it] = true;
                    myQueue.push(*it);
                    
                } else if(color[*it] == color[node]) {
                    cout<< "Not Bipartite" << endl;
                    return false;
                }
            }
        }
    }
    cout<<"Bipartite" << endl;
    return true;
    
}

Graph Graph::getTranspose(){
    Graph G(V);
    for (int i = 0 ; i < V ; i++) {
        list<int>:: iterator it;
        for (it = adj[i].begin(); it != adj[i].end(); it++) {
            G.adj[*it].push_back(i);
        }
    }
    
    return G;
}

bool Graph::isEularianCycle() {
    if (!isSC()) {
        return false;
    }
    
    // Finally check the in and out degrees and figure out if Eularian cycle exists
    
    
    return true;
}

bool Graph::isSC() {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    
    int n;
    for (n = 0; n < V; n++)
        if (adj[n].size() > 0)
            break;
    DFSUtil(n, visited);

    
    for (int i = 0; i < V; i++)
        if (adj[i].size() > 0 && visited[i] == false)
            return false;

    Graph gr = getTranspose();

    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    gr.DFSUtil(n, visited);
    

    for (int i = 0; i < V; i++)
        if (adj[i].size() > 0 && visited[i] == false)
            return false;
    
    return true;
}

void Graph::topologicalSortingUtil(int n, bool * visited, stack<int> &s) {
    visited[n] = true;
    list<int>:: iterator it;
    for (it = adj[n].begin(); it != adj[n].end(); it++) {
        if (!visited[*it]) {
            topologicalSortingUtil(*it, visited, s);
        }
    }
    s.push(n);// Add it only after all vertices are processed
}

void Graph::topologicalSorting() {
    
    stack<int> s;
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    // Call Util function which will populate the Stack based on DFS traversal,
    // Only after all the nodes adjacent are processed
    for (int i = 0; i < V ; i++) {
        if (!visited[i]) {
            topologicalSortingUtil(i, visited, s);
        }
    }
    
    // Once stack is populated
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}


