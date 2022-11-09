#include<iostream>
using namespace std;

int peak(int arr[], int n){
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;

    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s = mid+1;
        }
        else{
            e = mid;
        }
    }
    return s;
}

int main(){
    
    int arr[] = {1,3,5,10,7,5,3,0};
    cout<<peak(arr,8);

    return 0;
}