#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter n : ";
    cin>>n;
    for(int i=1; i<=n; i++){
        int space = i-1;
        for(int j=1; j<=space; j++){
            cout<<" ";
        }
        for(int j=n; j>=i; j--){
            cout<<"*";
        }

        cout<<endl;
    }
    return 0;
}