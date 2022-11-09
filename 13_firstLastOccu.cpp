#include<iostream>
using namespace std;

int firstOccur(int arr[],int n, int key){
    int st=0;
    int en = n-1;
    int mid = st + (en-st)/2;
    int ans = -1;

    while(st<=en){
        if(arr[mid]==key){
            ans = mid;
            en = mid-1;
        }
        else if(arr[mid]<key){
            st = mid++;
        }
        else{
            en = mid--;
        }
        mid = st + (en-st)/2;
    }
    return ans;
}

int LastOccur(int arr[],int n, int key){
    int st=0;
    int en = n-1;
    int mid = st + (en-st)/2;
    int ans = -1;

    while(st<=en){
        if(arr[mid]==key){
            ans = mid;
            st = mid+1;
        }
        else if(arr[mid]<key){
            st = mid++;
        }
        else{
            en = mid--;
        }
        mid = st + (en-st)/2;
    }
    return ans;
}

int main(){
    int arr[9]={1,1,1,4,4,6,6,6,6};
    cout<<firstOccur(arr,9,4);
    cout<<LastOccur(arr,9,4);
    return 0;
}