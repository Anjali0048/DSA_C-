#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int ele){
    // base case
    if(s.empty()){
        s.push(ele);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    insertAtBottom(s,ele);
    s.push(num);

}

void reverseStack(stack<int> &stack){

    // base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    reverseStack(stack);
    insertAtBottom(stack,num);
}

int main(){
    
    return 0;
}