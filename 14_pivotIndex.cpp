// SOME PART IS WRONG
#include<iostream>
using namespace std;

int pivot(int arr[], int n){
    int s=0, e=n-1;
    int sum1 = arr[0];
    int sum2 = arr[n-1];

    while(s<e){
        if(sum1<sum2){
            s++;
            sum1 += arr[s];
        }
        else if(sum1>sum2){
            e--;
            sum2 += arr[e];
        }
        if(sum1 == sum2){
            return s+1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,7,3,6,5,6};
    cout<<pivot(arr,6);
    return 0;
}
