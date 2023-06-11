#include <bits/stdc++.h>
using namespace std;

// topological sort means printing all the dependent vertices after the vertices which its dependent on.

// This solution is BFS approach
// 1.we create an array indegree which contains in-degree of all the vertices
// 2. add all the vertices which have in-degree = 0 to q
// 3.traverse the q untill it gets empty
// i. add that element to the ans
// ii. traverse all the children of that vertex with in-degree = 0 and reduce there in-degree by 1
// iii. if we get a vertex with in-degree = 0 add it to the queue

vector<int> topological_sort(vector<vector<int>> adj)
{
    vector<int> indegree = getInDegrees(adj);
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int tp;
    while (!q.empty())
    {
        tp = q.front();
        ans.push_back(tp);
        q.pop();
        for (int i = 0; i < adj[tp].size(); i++)
        {
            indegree[adj[tp][i]]--;
            if (indegree[adj[tp][i]] == 0)
                q.push(adj[tp][i]);
        }
    }
    return ans;
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