#include<iostream>
#include<algorithm>
using namespace std;

int sort012(int *arr, int n){
    int lo = 0;
    int mid = 0;
    int hi = n-1;

    while(lo<=hi){
        switch(arr[mid]){
            case 0 :
                swap(arr[lo++],arr[mid++]);
                break;

            case 1 :
                mid++;
                break;
            
            case 2 :
                swap(arr[hi--],arr[mid]);
                break;
        }
    }
}

int main(){
    
    

    return 0;
}