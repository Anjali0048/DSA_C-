#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter n : ";
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<j<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        for(int j=n-i; j>=1; j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}