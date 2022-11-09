#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> findAllDuplicate(vector<int> &arr) 
{
    
    int count = 1;
    vector<int> res;
    if(arr.size()==0){
        return res;
    }
    sort(arr.begin(),arr.end());
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==arr[i+1]){
            count++;
            if(count==2){
                res.push_back(arr[i]);
                count=1;
            }
        }
        else{
            count = 1;
        }
    }
    sort(res.begin(),res.end());
    return res;

    
}

int main(){
    
    vector<int> v;
    

    return 0;
}
