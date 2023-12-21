#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neigh : adj[node]){
      if(!visited[neigh]){
        bool cycleDetected = checkCycleDFS(neigh,visited, dfsVisited, adj);
        if(cycleDetected)
          return true;
      }
      else if(dfsVisited[neigh]){
        return true;
      }
    }
    dfsVisited[node]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
      int u = edges[i].first;
      int v = edges[i].second;

      adj[u].push_back(v);
    }

    // call dfs for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for(int i=1; i<=n; i++){
      if(!visited[i]){
        bool cycleFound = checkCycleDFS(i, visited,dfsVisited, adj);
        if(cycleFound)
          return true;
      }
    }
    return false;
}