#include<iostream>
using namespace std;

class Node{

    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
};

void reverseDLL(Node* &head){

    Node* temp = NULL;
    Node* curr = head;

    while(curr != NULL){
        temp = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = temp;
        curr = curr -> prev;
    }

    if(temp != NULL){
        head = temp -> prev;
    }
}

int main(){
    
    return 0;
}