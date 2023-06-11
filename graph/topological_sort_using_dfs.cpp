#include <bits/stdc++.h>
using namespace std;

// create a stack
// iterate from a vertex
//  append all the vertices which are dependent on it and then add source vertex in stack

void dfs(vector<vector<int>> adj, vector<bool> visited, stack<int> &st, int source)
{
    visited[source] = true;
    for (int i = 0; i < adj[source].size(); i++)
    {
        if (!visited[adj[source][i]])
        {
            dfs(adj, visited, st, adj[source][i]);
        }
    }
    st.push(source);
}

vector<int> topological_sort_using_dfs(vector<vector<int>> adj)
{
    stack<int> st;
    int n = adj.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(adj, visited, st, i);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    return 0;
}