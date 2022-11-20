#include<iostream>
using namespace std;

// WRONG CODE

string Reverse(string s){
    int st = 0;
    int en = s.length()-1;
    while(st <= en){
        swap(s[st++],s[en--]);
    }
    return s;
}

string ReverseWords(string s){
    int i=0;
    while(s[i] != ' '){
        i++;
    Reverse(s);
    }
    return s;
}

int main(){
    string s = "Anjali Singh";
    cout<<ReverseWords(s);
    return 0;
}