#include<iostream>
#include<vector>
using namespace std;

vector<int> Rotate(vector<int> arr, int k){
    vector<int> temp(arr.size());
    for(int i=0; i<arr.size(); i++){
        temp[(i+k) % arr.size()] = arr[i];
    }
    arr = temp;
    return arr;
}

void print(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> arr = {1,2,3,4,5,6,7};
    vector<int> ans = Rotate(arr,3);
    print(ans);
    
    return 0;
}