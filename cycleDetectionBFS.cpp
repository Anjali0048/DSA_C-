// directed graph

#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  // create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }

  // find all indegrees
    vector<int> indegree(n);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    // 0 indegree walo ko push kardo
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    } 

    // do bfs
    int cnt = 0;
    while(q.empty()){
        int front = q.front();
        q.pop();
        
        cnt++;

        for (auto neigh : adj[front]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0){
                q.push(neigh);
            }
        }
    }

    if( cnt == n ) 
        return false;
    else   
        return true;
}