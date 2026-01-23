// DFS
/*
    ek unordered map lenge
    ek stack Data structure lenge to traverse to depth
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i]) 
        {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> DFS(int V, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    prepareAdjList(adj, edges);

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main()
{
    // Test Case 1: Connected graph
    int V1 = 5;
    vector<pair<int, int>> edges1 = {
        {0, 1}, {0, 2}, {1, 3}, {2, 4}};
    auto result1 = DFS(V1, edges1);
    cout << "DFS Components (Test 1):\n";
    for (auto comp : result1)
    {
        for (int node : comp)
            cout << node << " ";
        cout << endl;
    }

    // Test Case 2: Disconnected graph
    int V2 = 6;
    vector<pair<int, int>> edges2 = {
        {0, 1}, {2, 3}, {4, 5}};
    auto result2 = DFS(V2, edges2);
    cout << "DFS Components (Test 2):\n";
    for (auto comp : result2)
    {
        for (int node : comp)
            cout << node << " ";
        cout << endl;
    }

    // Test Case 3: Single node graph
    int V3 = 1;
    vector<pair<int, int>> edges3 = {};
    auto result3 = DFS(V3, edges3);
    cout << "DFS Components (Test 3):\n";
    for (auto comp : result3)
    {
        for (int node : comp)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}