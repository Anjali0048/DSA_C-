#include<iostream>
#include<vector>
using namespace std;

vector<int> Reverse(vector<int> arr, int m){
    int s = m+1;
    int e = arr.size()-1;
    while(s<=e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    return arr;
}

void print(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    vector<int> ans = Reverse(arr,2);
    print(ans);
    return 0;
}