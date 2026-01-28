#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits.h>
#include <algorithm>
using namespace std;

void dfs(int node, int parent, vector<int> &dis, vector<int> &low, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &ap, int &timer)
{

    visited[node] = true;
    dis[node] = low[node] = timer++;
    int child = 0;
    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!visited[nbr])
        {
            dfs(nbr, node, dis, low, visited, adj, ap, timer);
            low[node] = min(low[node], low[nbr]);

            if (low[nbr] >= dis[node] && parent != -1)
            {
                ap[node] = true;
            }

            child++;
        }
        else
        {
            low[node] = min(low[node], dis[nbr]);
        }
    }

    if (parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}

int main()
{

    vector<pair<int, int>> edges = {{0, 3}, {0, 4}, {0, 1}, {1, 2}, {3, 4}};

    // create a adj list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int n = 5;

    int timer = 0;

    vector<int> dis(n, -1);
    vector<int> low(n, -1);
    vector<int> parent(n, -1);
    unordered_map<int, bool> visited;
    vector<int> ap(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, dis, low, visited, adj, ap, timer);
        }
    }

    cout << "articulation points are as followed :->" << endl;
    for (int i = 0; i < n; i++)
    {
        if (ap[i] != 0)
        {
            cout << i << " ";
        }
    }cout<<endl;

    return 0;
}