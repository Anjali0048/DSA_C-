#include<iostream>
using namespace std;

class Node{

    public :
        int data;
        Node* next;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }

        ~Node(){
            int value = this -> data;
            if(this -> next != NULL){
                delete next;
                next = NULL;
            }
            cout << "memory is free for node with data " << value << endl;
        }
};

void insertNode(Node* &tail, int element, int d){

    // empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;   
    }
    else{
        // non-empty list
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }

        // element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void deleteNode(Node* &tail, int val){

    // empty list
    if(tail == NULL){
        cout << "List is empty " << endl;
        return;
    }
    else{

        Node* prev = tail; 
        Node* curr = prev -> next;

        while(curr -> data != val){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;

        // 1 node LL
        if(curr == prev){
            tail = NULL;
        }

        //  >=2 Node LL
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }    
}

void print(Node* tail){

    Node* temp = tail;

    if(tail == NULL){
        cout << "tail is empty" <<endl;
        return;
    }
    do{
        cout << tail->data << " ";
        tail = tail -> next;
    }

    while(tail != temp);
    cout << endl;
}

int main(){

    Node* tail = NULL;

    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,10);
    print(tail);

    insertNode(tail,10,18);
    print(tail);

    insertNode(tail,3,20);
    print(tail); 

    deleteNode(tail,3);
    print(tail); 
    
    return 0;
}