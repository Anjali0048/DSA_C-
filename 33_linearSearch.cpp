#include<iostream>
using namespace std;

bool linearSearch(int arr[], int n, int target){
    
    if(n==0){
        return false;
    }
    if(arr[0]==target){
        return true;
    }
    else{
        return linearSearch(arr+1,n-1,target);
    }
}

int main(){

    int arr[5] = {3,5,1,2,6};
    bool ans = linearSearch(arr,5,4);
    
    if(ans){
        cout<<"present"<<endl;
    }
    else{
        cout<<"absent"<<endl;
    }
    
    return 0;
}