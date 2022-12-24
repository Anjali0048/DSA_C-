#include<iostream>
using namespace std;

class Node {

    public :
        int data;
        Node* next;

    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //  destructor
    // ~Node() {
    //     int value = this -> data;
    //     //memory free
    //     if(this->next != NULL) {
    //         delete next;
    //         this->next = NULL;
    //     }
    //     cout << " memory is free for node with data " << value << endl;
    // }
};

void insertAtHead(Node* &head, int d){

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &head, int d){

    Node* temp = new Node(d);
    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr -> next;
    }
    ptr -> next = temp;
    temp -> next = NULL;
}

void insertAfterNode(Node* &head, Node* prevNode, int d){
    Node* temp = new Node(d);
    temp -> next = prevNode -> next;
    prevNode -> next = temp;
}

void insertAtIndex(Node* &head, int d, int index){

    // insert at start
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

    // insert at last
    if(ptr -> next == NULL){
        insertAtTail(head,d);
        return;
    }
}


void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    } 
    cout<<endl;
}

int main(){

    // created a new node
    Node* node1 = new Node(20);
    Node* head = node1;

    // print(head);
    insertAtHead(head, 10);
    insertAtTail(head,30);
    insertAtTail(head,40);
    insertAtTail(head,50);
    insertAtIndex(head,25,3);
    insertAfterNode(head,head,35);
    print(head);

    deleteNode(3,head);
    print(head);

    
    return 0;
}