#include<iostream>
using namespace std;

void reverse( string& str, int s, int e){

    if(s>e){
        return ;
    }
    swap(str[s],str[e]);
    s++;
    e--;

    reverse(str,s,e);

}

int main(){
    
    string name = "Satyam";
    reverse(name,0,name.length()-1);
    cout<<name;

    return 0;
}