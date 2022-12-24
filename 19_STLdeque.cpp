#include<iostream>
#include<deque>
using namespace std;

int main(){
    
    deque<int> d;
    d.push_back(5);
    d.push_front(4);
    d.push_front(3);
    d.push_front(2);
    d.push_front(1);

    for(int i : d){
        cout << i << " ";
    }
    cout << endl;

    d.pop_back();
    d.pop_front();

    for(int i : d){
        cout << i << " ";
    }
    cout << endl;

    cout << "first index element -> " << d.at(1) << endl;

    cout << "front : " << d.front() << endl;
    cout << "back : " << d.back() << endl;
    cout << "empty or not : " << d.empty() << endl;

    d.erase(d.begin(),d.begin()+1);
    cout << "after erase size : " << d.size() << endl;

    for(int i : d){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}