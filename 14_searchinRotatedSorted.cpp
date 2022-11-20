#include<iostream>
using namespace std;

int binarySearch(int arr[],int s, int e, int key){
    int st=s;
    int en = e;
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

int getPivot(int arr[], int n){
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;

    while(s<e){

        if(arr[mid]>=arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return s;
}

int Rotated(int arr[], int n, int k){
    int pivot = getPivot(arr,n);
    if(k>=arr[pivot] && k<=arr[n-1]){
        return binarySearch(arr,pivot,n-1,k);
    }
    else{
        return binarySearch(arr,0,pivot-1,k);
    }
}

int main(){
    int arr[] = {7,9,1,2,3};
    cout<<Rotated(arr,5,2);
    return 0;
}