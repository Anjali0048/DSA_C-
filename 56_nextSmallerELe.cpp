#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerEle(vector<int> &arr, int n){

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    // for previous smaller element just traverse the loop in reverse order
    for(int i=n-1; i>=0; i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(){

    return 0;
}