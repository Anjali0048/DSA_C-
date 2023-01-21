#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    
    stack<int> s;
    
    for(int i=0; i<k; i++){
        int ele = q.front();
        q.pop();
        s.push(ele);
    }
    
    while(!s.empty()){
        int ele = s.top();
        s.pop();
        q.push(ele);
    }
    int n = q.size();
    for(int i=0; i<n-k; i++){
        int ele = q.front();
        q.pop();
        q.push(ele);
    }
    return q;
}


int main(){
    
    return 0;
}