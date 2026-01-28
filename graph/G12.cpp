#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits.h>
#include <algorithm>
#include <stack>
using namespace std;


void dfs1(int node,unordered_map<int,bool> &vis,stack<int> &st,unordered_map<int,list<int>> &adj){
    vis[node] = true;
    for(auto neighbour: adj[node]){
        if(!vis[neighbour]){
            dfs1(neighbour,vis,st,adj);
        }
    }

    st.push(node);
}

void dfs(int node,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj){
    vis[node] = true;

    for(auto nbr:adj[node]){
        if(!vis[nbr]){
            dfs(nbr,vis,adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // topological sort
    stack<int> s;
    unordered_map<int,bool> vis;

    for(int i = 0;i<v;i++){
        if(!vis[i]){
            dfs1(i,vis,s,adj);
        }
    }

    // create a transpose of a graph
    unordered_map<int,list<int>> trans;

    for(int i = 0;i<v;i++){
        vis[i] = false;
        for(auto nbr:adj[i]){
            trans[nbr].push_back(i);
        }
    }

    // dfs call for above ordering
    int count = 0;
    while(!s.empty()){
        int top = s.top();
        s.pop();

        if(!vis[top]){
            count++;
            dfs(top,vis,trans);

        }
    }

    return count;
}

int main()
{

    return 0;
}