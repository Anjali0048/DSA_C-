#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    queue<int> q;
    unordered_map<int,bool> visited;
    
    q.push(0);
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        visited[frontNode] = 1;
        ans.push_back(frontNode);
        
        for(auto neighbour : adj[frontNode]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
            }
        }
    }
    return ans;
}

int main(){ 
    
    return 0;
}