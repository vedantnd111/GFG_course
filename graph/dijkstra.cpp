#include<bits/stdc++.h>
using namespace std;

// Dikstra's algorithm to find minimum distance to all vertices from source
// Does no work when path weight is negative
// Its a greedy solution and similar to prim's algorithm

// Time complexity = O(V^2)
// with adj list and min heap it time complexity would be O(ElogV)

vector<int> dijkstra(vector<vector<int>> graph,int n,int source) {
    // distance[i] represent min distance to go to i from source
    vector<int> distance(n,INT_MAX);
    // finalized[i] represent whether min distance for ith vertex is found or not
    vector<bool> finalized(n,false);
    distance[source] = 0;
    finalized[source]= true;
    int u;
    for(int count = 0;count< n-1;count++) {
        u = -1;
        for(int i = 0;i<n;i++) {
            if(!finalized[i] && (u == -1 || distance[u]>distance[i])) {
                u = i;
            }
        }
        finalized[u] = true;
        for(int i = 0;i<n;i++) {
            if(!finalized[i] && graph[u][i] != 0) {
                distance[i] = min(distance[i],distance[u]+graph[u][i]);
            }
        }
    }
    return distance;
}

int main()
{
    return 0;
}