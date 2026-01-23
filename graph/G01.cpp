#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges)
{
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node )
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i : adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    for(int i = 0; i < vertex; i++){
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

int main()
{
    // Test Case 1: Simple connected graph
    int vertex1 = 5;
    vector<pair<int,int>> edges1 = {
        {0,1}, {0,2}, {1,3}, {2,4}
    };
    vector<int> result1 = BFS(vertex1, edges1);
    cout << "BFS Traversal (Test 1): ";
    for(int node : result1) cout << node << " ";
    cout << endl;

    // Test Case 2: Disconnected graph
    int vertex2 = 6;
    vector<pair<int,int>> edges2 = {
        {0,1}, {2,3}, {4,5}
    };
    vector<int> result2 = BFS(vertex2, edges2);
    cout << "BFS Traversal (Test 2): ";
    for(int node : result2) cout << node << " ";
    cout << endl;

    // Test Case 3: Single node graph
    int vertex3 = 1;
    vector<pair<int,int>> edges3 = {};
    vector<int> result3 = BFS(vertex3, edges3);
    cout << "BFS Traversal (Test 3): ";
    for(int node : result3) cout << node << " ";
    cout << endl;

    return 0;
}