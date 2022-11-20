#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
                arr[j+1]=arr[j];
                j--;
        }
        arr[j+1]=temp;
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
    InsertionSort(arr,n);
    printArr(arr,n);
    return 0;
}