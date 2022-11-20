#include<iostream>
using namespace std;

int power(int x, int n){

    if(n==0){
        return 1;
    }

    if(n==1){
        return x;
    }
    // return x * power(x,n-1);

    int ans = power(x,n/2);

    if(n%2 == 0){
        return ans * ans;
    }
    else{
        return x * ans * ans;
    }
    
}

int main(){

    cout<<power(4,3);
    
    return 0;
}