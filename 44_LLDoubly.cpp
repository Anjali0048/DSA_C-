#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        // constructor
        Node(int d){
            this -> data = d;
            this -> prev = NULL;
            this -> next = NULL;
        }

        ~Node(){
            int val = this -> data;
            if(next != NULL){
                delete next;
                next = NULL;
            }
            cout << "memory free for node with data " << val << endl;
        }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* &head, int d){

    //empty list 
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, int d){

    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

// void insertAtTail(Node* &head, int d){
//     Node* temp = new Node(d);
    
//     Node* ptr = head;
//     while(ptr != NULL){
//         ptr = ptr -> next;
//     }
//     ptr -> next = temp;
//     temp -> prev = ptr;
//     temp -> next = NULL;
// }

void insertAtPosition(Node* &head, int index, int d){

    if(index == 1){
        insertAtHead(head,d);
        return;
    }
    
    Node* temp = new Node(d);
    Node* ptr = head;
    int i=1;
    while(i != index-1){
        ptr = ptr -> next;
        i++;
    }
    temp -> next = ptr -> next;
    ptr -> next = temp;
    temp -> prev = ptr;
    
}

void deleteNode(Node* &head, int index){

    // delete at first
    if(index == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }

    else{

        // deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;
        
        int i=1;
        while(i != index-1){
            prev = curr;
            curr = curr -> next;
            i++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;
    }
    

}

int main(){

    Node* node1 = new Node(15);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    // cout << getLength(head) << endl;

    insertAtHead(head, 11);
    print(head);
    insertAtTail(tail,20);
    print(head);
    insertAtTail(tail,2);
    print(head);
    insertAtHead(head,4);
    print(head);
    insertAtPosition(head,3,10);
    print(head);
    deleteNode(head,1);
    print(head);
    deleteNode(head,3);
    print(head);
    
    return 0;
}