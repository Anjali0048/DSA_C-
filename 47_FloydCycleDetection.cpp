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
};

Node* floydDetectLoop(Node* head){

    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){

        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;

        if(slow == fast){
            cout << " cycle present at element : " << slow->data << endl;
            // this slow/fast node may be present at any point in the cycle this is not necessarily the beginning of cycle
            return slow;
        }
    }
    return NULL;
}

// to find the starting node of the circular loop
Node* StartingNode(Node* head){

    if(head == NULL){
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);

    if(intersection == NULL){
        return NULL;
    }

    Node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}

// to remove the loop
Node* removeLoop(Node* head){

    if(head == NULL){
        return NULL;
    }

    Node* startOfLoop = StartingNode(head);

    if(startOfLoop == NULL){
        return head;
    }

    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop){
        temp = temp -> next;
    }
    temp -> next = NULL;
    return head;
}


int main(){
    
    return 0;
}