// Finding articulation point in a graph

// 1. Do a dfs tree traversal of a graph.
// 2. If root has 2 children then its an articulation point.
// 3. while dfs traversal assign each vertex discovery time(time at which the vertex is reached) and
// low value(lowest discovery time reachable for this node from its children)
// for an edge u->v if discovery_time[u]<=low_value[v] then u is an articulation point

// logic behind this is if from any of u's children we can not reach any of u's ancestor so if we remove u then its children
// becomes disconnected

// C++ program to find articulation points in an undirected graph
#include <bits/stdc++.h>
using namespace std;

// A recursive function that find articulation
// points using DFS traversal
// adj[] --> Adjacency List representation of the graph
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
// discovery time) that can be reached from subtree
// rooted with current vertex
// parent --> Stores the parent vertex in DFS tree
// isAP[] --> Stores articulation points
void APUtil(vector<int> adj[], int u, bool visited[],
            int disc[], int low[], int &time, int parent,
            bool isAP[])
{
    // Count of children in DFS Tree
    int children = 0;

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;

    // Go through all vertices adjacent to this
    for (auto v : adj[u])
    {
        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v])
        {
            children++;
            APUtil(adj, v, visited, disc, low, time, u, isAP);

            // Check if the subtree rooted with v has
            // a connection to one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // If u is not root and low value of one of
            // its child is more than discovery value of u.
            if (parent != -1 && low[v] >= disc[u])
                isAP[u] = true;
        }

        // Update low value of u for parent function calls.
        else if (v != parent)
            low[u] = min(low[u], disc[v]);
    }

    // If u is root of DFS tree and has two or more children.
    if (parent == -1 && children > 1)
        isAP[u] = true;
}

void AP(vector<int> adj[], int V)
{
    int disc[V] = {0};
    int low[V];
    bool visited[V] = {false};
    bool isAP[V] = {false};
    int time = 0, par = -1;

    // Adding this loop so that the
    // code works even if we are given
    // disconnected graph
    for (int u = 0; u < V; u++)
        if (!visited[u])
            APUtil(adj, u, visited, disc, low,
                   time, par, isAP);

    // Printing the APs
    for (int u = 0; u < V; u++)
        if (isAP[u] == true)
            cout << u << " ";
}