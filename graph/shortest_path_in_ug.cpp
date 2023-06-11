// Find shortest path to every vertex from source in an undirected graph

// We'll use bfs traversal to solve this problem
// because in BFS traversal we traverse elements which are 1 unit away then 2 unit away and so on.

#include<bits/stdc++.h>
using namespace std;

// adj = adjacency list of the graph

// this code is written with consideration that vertex value lies in [0,n-1]
// if vertex value has any other type like string we can use hash map for adj,distance and visited

vector<int> shortest_dist(vector<vector<int>> adj,int source,int n) {
    // distance will contain shortest distance to reach node at index i
    vector<int> distance(n,INT_MAX);
    // visited will check if the node is visited or not
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(source);
    distance[source] = 0;
    visited[source] = true;
    int tp;
    while(!q.empty()) {
        tp = q.front();
        q.pop();
        for(int i = 0;i < adj[tp].size();i++) {
            if(!visited[adj[tp][i]]) {
                q.push(adj[tp][i]);
                distance[adj[tp][i]] = distance[tp]+1;
                visited[adj[tp][i]] = true;
            }
        }
    }
    return distance;
}