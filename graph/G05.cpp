#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
#include<stack>
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


void topoSort(int node,stack<int> &st, unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adj){
    visited[node] = 1;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour,st,visited,adj);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<pair<int,int>> &edges, int v, int e) {
    unordered_map<int,list<int>> adj;
    prepareAdjList(adj,edges);
/*
    Hum log vector visited use kar sakte hai to get safe from TLE
*/
    unordered_map<int,bool> visited;
    stack<int> st;
    for(int i = 1;i<=v;i++){
        if(!visited[i]){
            topoSort(i,st,visited,adj);
        }
    }

    vector<int> ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();

    }

}

int main()
{

    return 0;
}