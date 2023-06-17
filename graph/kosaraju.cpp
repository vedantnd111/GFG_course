#include <bits/stdc++.h>
using namespace std;

// Kosaraju's algorithm
// used determine number of strongly connected components in a graph

// method-1
// 1.Do a dfs traversal of all elments and arrange them in decreasing order dfs ending time store it in vect array - O(V+E)
// 2.reverse all the edges - O(V+E)
// 3.traverse the graph in order of vect array - O(V+E)

// Implementation
// Implementation is same as topological sort

// ************************** Step 2 ***************************************

void dfs(vector<vector<int>> graph, vector<int> &visited, int source, vector<vector<int>> &ans, vector<int> &temp)
{
    visited[source] = true;
    for (int i = 0; i < graph[source].size(); i++)
    {
        if (!visited[graph[source][i]])
        {
            temp.push_back(graph[source][i]);
            dfs(graph, visited, graph[source][i], ans, temp);
        }
        else
        {
            ans.push_back(temp);
        }
    }
}

// ************************** Step 3 ***************************************

// ************************** Step 3 ***************************************

void dfsRec(vector<vector<int>> graph, vector<int> &visited, stack<int> &st, int source)
{
    visited[source] = true;
    for (int i = 0; i < graph[source].size(); i++)
    {
        if (!visited[graph[source][i]])
        {
            dfsRec(graph, visited, st, graph[source][i]);
        }
    }
    st.push(source);
}
// ************************** Step 3 ***************************************

vector<vector<int>> reverseAllEdge(vector<vector<int>> graph, int n)
{
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            ans[graph[i][j]].push_back(i);
        }
    }
    return ans;
}

void kosaraju(vector<vector<int>> graph, int n)
{
    stack<int> st;
    vector<int> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsRec(graph, visited, st, i);
        }
    }
    // step2 reverse all the edges
    // in adjacency matrix we can do this by transposing matrix
    // in adjacency list it can be done by traversing
    graph = reverseAllEdge(graph, n);
    vector<int> visited2(n, false);
    vector<vector<int>> ans;
    vector<int> temp;
    // Step3
    while (!st.empty())
    {
        if (!visited2[st.top()])
        {
            temp.push_back(st.top());
            dfs(graph, visited2, st.top(), ans, temp);
            st.pop();
        }
    }
}

int main()
{
    return 0;
}