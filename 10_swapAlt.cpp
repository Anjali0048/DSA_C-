#include<iostream>
using namespace std;

void swapAlt(int arr[], int n){
    for(int i=0; i<n; i+=2){
        swap(arr[i],arr[i+1]);
    }
}

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    print(arr,6);
    swapAlt(arr,6);
    print(arr,6);
    return 0;
}