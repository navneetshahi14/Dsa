#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
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

bool isCyclic(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;

    q.push(src);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adjList[front])
        {
            if (visited[neighbour] == true && neighbour != parent[front])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }

    return false;
}

string cycleDetection(vector<pair<int, int>> &edges, int n)
{
    unordered_map<int, list<int>> adjList;
    prepareAdjList(adjList, edges);

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclic(i, visited, adjList);
            if (ans == 1)
            {
                return "YES";
            }
        }
    }

    return "NO";
}

int main()
{
    // Test Case 1: Graph with a cycle
    int n1 = 4;
    vector<pair<int, int>> edges1 = {
        {0, 1}, {1, 2}, {2, 0}, {2, 3}};
    cout << "Cycle Detection (Test 1): " << cycleDetection(edges1, n1) << endl;
    // Expected: YES

    // Test Case 2: Graph without a cycle
    int n2 = 5;
    vector<pair<int, int>> edges2 = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}};
    cout << "Cycle Detection (Test 2): " << cycleDetection(edges2, n2) << endl;
    // Expected: NO

    // Test Case 3: Disconnected graph with a cycle in one component
    int n3 = 6;
    vector<pair<int, int>> edges3 = {
        {0, 1}, {1, 2}, {2, 0}, // cycle in component 1
        {3, 4},
        {4, 5} // no cycle in component 2
    };
    cout << "Cycle Detection (Test 3): " << cycleDetection(edges3, n3) << endl;
    // Expected: YES

    // Test Case 4: Single node graph
    int n4 = 1;
    vector<pair<int, int>> edges4 = {};
    cout << "Cycle Detection (Test 4): " << cycleDetection(edges4, n4) << endl;
    // Expected: NO

    return 0;
}