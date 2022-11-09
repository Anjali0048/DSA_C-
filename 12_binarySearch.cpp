#include<iostream>
using namespace std;

int binarySearch(int arr[],int n, int key){
    int st=0;
    int en = n-1;
    int mid = st + (en-st)/2;

    while(st<=en){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            st = mid++;
        }
        else{
            en = mid--;
        }
        mid = st + (en-st)/2;
    }
    return -1;
}

int main(){
    int arr[7]={1,3,5,8,9,14,15};
    cout<<binarySearch(arr,7,3);
    return 0;
}