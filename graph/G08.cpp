#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<pair<int, int>>> &adj, vector<vector<int>> edges, int vertices, int edge)
{
    for (int i = 0; i < edge; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // prepare adjancy list
    unordered_map<int, list<pair<int, int>>> adj;

    prepareAdjList(adj, vec, vertices, edges);

    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        // fetch top record
        auto top = *(st.begin());

        int nodeDist = top.first;
        int topNode = top.second;

        // remove top record now
        st.erase(st.begin());

        // traverse on neighbours
        for (auto neighbour : adj[topNode])
        {
            if (nodeDist + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                if (record != st.end())
                {
                    st.erase(record);
                }

                dist[neighbour.first] = nodeDist + neighbour.second;

                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}

int main()
{

    return 0;
}