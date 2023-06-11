#include <bits/stdc++.h>
using namespace std;

// traverse through the graph and check, is an already visited vertex getting visited again from its non parent vertex

// Time complexity = O(V+E)
// space complexity = O(V*E) [size of adj list]

bool dfs(vector<vector<int>> adj, vector<bool> &visited, int source, int parent)
{
    visited[source] = true;
    for (int i = 0; i < adj[source].size(); i++)
    {
        if (visited[adj[source][i]] && parent != adj[source][i])
        {
            return true;
        }
        if (!visited[adj[source][i]] && parent != adj[source][i])
        {
            return dfs(adj, visited, adj[source][i], source);
        }
    }
    return false;
}

bool detect_cycle(vector<vector<int>> adj)
{
    int n = adj.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if(visited[i] == false) {
        bool temp = dfs(adj, visited, i, -1);
        if(temp) return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}