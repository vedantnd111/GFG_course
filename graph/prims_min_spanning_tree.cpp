#include<bits/stdc++.h>
using namespace std;

// what is a spanning tree?
// spanning tree of a graph is a tree which connects all of its vertices such that resultant tree doesn't have a cycle

// Prims algorithm to find minimum spanning tree is based on greedy approach
// We create 2 sets one contains elements included in min spanning tree and other is for other elements
// In code we've used mset to check if a vertex is in min spanning tree or not


// Time Complexity = O(V*V) with adjacency matrix
// O(ElogV) with adj list and min heap
// Space complexity = O(V)

int primMST(vector<vector<int>> graph,int v) {
    // key[i] contains minimum weighted edge to vertex i
    vector<int> key(v,INT_MAX);
    // mset[i] tells if ith vertex is in minimum spanning tree or not
    vector<int> mset(v,false);
    int res = 0;
    key[0] = 0;
    for(int count = 0;count < v;count++) {
        int u = -1;
        // below for loop finds a vertex which is reachable with min weight and its not already in min spanning tree 
        for(int i = 0;i<v;i++) {
            if(!mset[i] && (u == -1 || key[u]>key[i])) {
                u = i;
            }
        }
        // include the vertex which is reachable with min weight in the min spanning tree and add its weight to the res
        mset[u] = true;
        res += key[u];

        // visit neighbours of u which are not in min spanning tree and find there minimum weight required to reach
        for(int j = 0;j<v;j++) {
            if(graph[u][j] != 0 && !mset[j]) {
                key[j] = min(key[j],graph[u][j]);
            }
        }
    }
    return res;
}