#include<iostream>
using namespace std;

bool isSorted(int arr[], int size){

    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool ans = isSorted(arr+1,size-1);
        return ans;
    }
}

int main(){
    
    int arr[5] = {1,3,0,7,9};
    bool ans = isSorted(arr,5);
    if(ans){
        cout<<"Sorted";
    }
    else{
        cout<<"not sorted";
    }

    return 0;
}