#include<bits/stdc++.h>
using namespace std;

//Time complexity: O(V+E)
// Space complexity: O(V) [distance array and topologicalSort array]

// Find shortest distance in directed acyclic graph (DAG)
// This solution is done using topological sort, for details regarding it refer topological_sort.cpp and topological_sort_using_dfs.cpp

// we are considering distance between any 2 vertices is 1

vector<int> shortest_distance_in_dag(vector<vector<int>> adj,vector<int> topologicalSort) {
    int n = adj.size();
    vector<int> visited(n,false);
    vector<int> distance(n,INT_MAX);

    for(int i = 0;i<topologicalSort.size();i++) {
        for(int j = 0;j<adj[topologicalSort[i]].size();j++) {
            if(distance[adj[topologicalSort[i]][j]] > (distance[topologicalSort[i]]+1)) {
                distance[adj[topologicalSort[i]][j]] = distance[topologicalSort[i]]+1;
            }
        }
    }
    return distance;
}

int main()
{
    return 0;
}