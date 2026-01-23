#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adj, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }
}

bool checkCycleDFS(int node, unordered_map<int, bool> visited, unordered_map<int, list<int>> adj, unordered_map<int, bool> dfsVisited)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = checkCycleDFS(neighbour,visited,adj,dfsVisited);
            if(cycleDetected) return true;
        }else if(dfsVisited[neighbour]){
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    prepareAdjList(adj, edges);

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = checkCycleDFS(i, visited, adj, dfsVisited);
            if (cycleFound)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    return 0;
}