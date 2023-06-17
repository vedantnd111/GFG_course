// Bellman ford algorithm
// Used to find single source shortest path for all vertices in a graph
// Its a Dynamic programming algo

// IDEA: we find all shortest path that are 1 edge length. Then shortest path that are 2 edge length.
// To find shorted path of i edge length we use shortest path of (i-1) edge length as its a DP algo.

// Algorithm: we relax all edges v-1 times.

// Time complexity : O(VE)
// Space complexity : O(V)

#include <bits/stdc++.h>
using namespace std;

int weight(int source, int dest)
{
    // this function will return distance from source to dist
    return 0;
}

vector<int> bellman_ford(vector<vector<int>> adj, int source)
{
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < adj[j].size(); j++)
            {
                dist[adj[i][j]] = min(dist[adj[i][j]], weight(i, adj[i][j]) + dist[i]);
            }
        }
    }

    // To find if there's any -ve weight cycle
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[j].size(); j++)
        {
            if (dist[adj[i][j]] > weight(i, adj[i][j]) + dist[i])
            {
                cout << "negative weight cycle\n";
            }
        }
    }
    return dist;
}
