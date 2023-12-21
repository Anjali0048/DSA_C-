// Cycle Detection In Undirected Graph
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

bool isCycleBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neigh : adj[curr]){
            if(visited[neigh] && neigh != parent[curr]){
                return true;
            }
            else if(!visited[neigh]){
                q.push(neigh);
                visited[neigh] = 1;
                parent[neigh] = curr;
            }
        }
    }
    return false;
}

// by using DFS
// parent = -1
bool isCycleDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
    visited[node] = 1;
    for(auto neigh : adj[node]){
        if(!visited[neigh]){
            bool cycleDetected = isCycleDFS(neigh, node, visited, adj);
            if(cycleDetected)
                return true;
        }
        else if(neigh != parent)
            return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = isCycleBFS(i, visited, adj);
            if(ans == 1)
                return "Yes";
        }
    }
    return "No";
}
