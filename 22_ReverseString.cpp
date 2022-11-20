#include<iostream>
using namespace std;

string Reverse(string s){
    int st = 0;
    int en = s.length()-1;
    while(st <= en){
        swap(s[st++],s[en--]);
    }
    return s;
}

int main(){
    string s = "Anjali Singh";
    cout<<Reverse(s);
    return 0;
}