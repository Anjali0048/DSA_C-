#include<iostream>
using namespace std;

class Node {

    public :
        int data;
        Node* next;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
};

Node* Reverse(Node* &head){

    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL; 

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward ;
    }
    return prev;
}

void ReverseRecursion(Node* &head, Node* curr, Node* prev){

    // base case
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr -> next;
    ReverseRecursion(head, forward, curr);
    curr -> next = prev;

}

// it will return head of the reversed LL
Node* OptimumReverseRecursion(Node* head){

    // base case
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* chotaHead = OptimumReverseRecursion(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return chotaHead;
}

int main(){
    
    return 0;
}