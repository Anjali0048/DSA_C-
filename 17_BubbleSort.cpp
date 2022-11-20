#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {64,25,12,22,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArr(arr,n);
    BubbleSort(arr,n);
    printArr(arr,n);
    return 0;
}