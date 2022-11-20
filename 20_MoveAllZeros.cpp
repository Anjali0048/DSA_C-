#include<iostream>
#include<vector>
using namespace std;

vector<int> MoveZeros(vector<int> arr){
    int i=0;
    for(int j=0; j<arr.size(); j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
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

    vector<int> v = {0,1,0,3,0,5,7,0,12};
    vector<int> ans = MoveZeros(v);
    print(ans);
    
    return 0;
}