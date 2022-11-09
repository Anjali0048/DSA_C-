#include<iostream>
#include<vector>
using namespace std;

vector<int> FindIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){

    vector<int> v;
    int a=0, b=0;
    while(a<n && b<m){
        if(arr1[a]==arr2[b]){
            v.push_back(arr1[a]);
            a++;
            b++;
        }
        else if(arr1[a]<arr2[b]){
            a++;
        }
        else{
            b++;
        }
    }
    return v;
}

int main(){
    
    return 0;
}