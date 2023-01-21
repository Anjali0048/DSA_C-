#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// using queue
void interLeaveQueue(queue<int> &q){

    queue<int> newQ;
    int mid = q.size()/2;

    int i=0;
    while(i < mid){
        newQ.push(q.front());
        q.pop();
        i++;
    }
    while(!newQ.empty()){
        q.push(newQ.front());
        newQ.pop();
        q.push(q.front());
        q.pop();
    }
}

// using stack
void interLeaveQueue2(queue<int> &q){

    stack<int> s;
    int mid = q.size()/2;

    for(int i=0; i<mid; i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i=0; i<mid; i++){
        q.push(q.front());
        q.pop();
    }
    for(int i=0; i<mid; i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }


}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue2(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}