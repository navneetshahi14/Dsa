#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adj, vector<pair<int,int>> edges){
    // directed graph adj list preparation
    for(int i = 0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v); // --> directed graph bana diya
    }
}

vector<int> topologicalSort(vector<pair<int,int>> &edges,int v,int e){

    // preparing adj list
    unordered_map<int,list<int>> adj;
    prepareAdjList(adj,edges);

    // finding all indegrees
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    // 0 --> Indegree nodes ko queue main push kardo
    queue<int> q;
    
    for(int i = 0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // do bfs


    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(int neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(indegree[neighbour]);
            }
        }
    }

    return ans;

}

int main()
{

    return 0;
}