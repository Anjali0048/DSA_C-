#include<iostream>
using namespace std;

bool binarySearch(int *arr,int s, int e, int key){

    int mid = s + (e-s)/2 ;

    if(s > e){
        return false;
    }

    if(arr[mid] == key){
        return true;
    }

    if(arr[mid] < key){
        return binarySearch(arr,mid+1,e,key);
    }

    else{
        return binarySearch(arr,s,mid-1,key);
    }

    return -1;

}

int main(){
    int n = 7;
    int s = 0;
    int e = n-1;
    int arr[7]={1,3,5,8,9,14,15};
    cout<<binarySearch(arr,s,e,14);

    return 0;
}