#include <bits/stdc++.h>
using namespace std;

// Detect cycle in a directed graph

// Time complexity = O(V+E)
// space complexity = O(V*E) [size of adj list + size of 2 1d vectors]

// soulution is similar to Detect cycle in a undirected graph
// traverse through the graph and check, if it is an already visited vertex getting visited again from its non parent vertex
// along with visited we keep rec array to check dfs() of an index is currently in execution or not
// if "u" vertex is already visited and if its active in recursion stack (rec) then return true

// ************************** DFS approach *************************************

bool dfs(vector<vector<int>> adj, vector<int> &visited, vector<int> rec, int source)
{
    visited[source] = true;
    rec[source] = true;
    for (int i = 0; i < adj[source].size(); i++)
    {
        if (!visited[adj[source][i]] && dfs(adj, visited, rec, i))
            return true;
        if (rec[adj[source][i]])
            return false;
    }
    rec[source] = false;
    return false;
}

bool detect_cycle_in_directed_graph(vector<vector<int>> adj)
{
    int n = adj.size();
    vector<int> visited(n, false);
    vector<int> rec(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(adj, visited, rec, i))
                return true;
        }
    }
    return false;
}

// ************************** DFS approach *************************************

int main()
{
    return 0;
}
