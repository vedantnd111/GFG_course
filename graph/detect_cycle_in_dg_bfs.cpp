#include <bits/stdc++.h>
using namespace std;

// Detect cycle in a directed graph using BFS
// this solution is done using topological sort [for explanation refer topological_sort.cpp]
// in topological we add vertex in the queue which have indegree = 0
// but in cyclic graph there would be a point when there will be no more vertices with indegree = 0
// so we count how many vertices can have indegree = 0 and store it in count
// if (count<n) return true else false

bool detect_cycle_in_directed_graph_bfs(vector<vector<int>> adj)
{
    vector<int> indegree = getInDegrees(adj);
    int n = adj.size();
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int tp, count = 0;
    while (!q.empty())
    {
        tp = q.front();
        count++;
        q.pop();
        for (int i = 0; i < adj[tp].size(); i++)
        {
            indegree[adj[tp][i]]--;
            if (indegree[adj[tp][i]] == 0)
                q.push(adj[tp][i]);
        }
    }
    return count != n;
}

vector<int> getInDegrees(vector<vector<int>> adj)
{
    vector<int> ans(adj.size(), 0);
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            ans[adj[i][j]]++;
        }
    }
    return ans;
}

int main()
{
    return 0;
}