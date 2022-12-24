#include<iostream>
#include<unordered_map>
using namespace std;

class Node{

    public :
        int data;
        Node* next;
        Node* random;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
            this -> random = NULL;

        }
};

class Solution {

    private :
        void insertAtTail(Node* &head, Node* &tail, int d){
            Node* newNode = new Node(d);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            else{
                tail -> next = newNode;
                tail = newNode;
            }
        }

    public :
        Node* copyLL(Node* head){
            
            // step1 : create a clone list
            Node* cloneHead = NULL;
            Node* cloneTail = NULL;
            Node* temp = head;

            while(temp != NULL){
                insertAtTail(cloneHead, cloneTail,temp->data);
                temp = temp -> next;
            }

            // step2 : Create a map
            unordered_map<Node*, Node*> oldToNewNode;

            Node* originalNode = head;
            Node* cloneNode = cloneHead; 
            while(originalNode != NULL){
                oldToNewNode[originalNode] = cloneNode;
                originalNode = originalNode -> next;
                cloneNode = cloneNode -> next;
            }
            originalNode = head;
            cloneNode = cloneHead;

            while(originalNode != NULL){
                cloneNode -> random = oldToNewNode[originalNode -> random];
                originalNode = originalNode -> next;
                cloneNode = cloneNode -> next;
            }
            return cloneHead;
        }


        Node* optimisedSol(Node* head){

            // step 1 : create a clone list

            Node* cloneHead = NULL;
            Node* cloneTail = NULL;

            Node* temp = head;
            while(temp != NULL){
                insertAtTail(cloneHead, cloneTail, temp->data);
                temp = temp -> next;
            }

            // step 2 : cloneNodes add in between Original List
            Node* originalNode = head;
            Node* cloneNode = cloneHead;

            while(originalNode != NULL && cloneNode != NULL){
                Node* next = originalNode -> next;
                originalNode -> next = cloneHead;
                originalNode = next;

                next = cloneNode -> next;
                cloneNode -> next = originalNode;
                cloneNode = next ;
            }

            // step 3 : random pointer copy
            temp = head;

            while(temp != NULL){
                if(temp -> next != NULL){
                    temp -> next -> random = temp -> random ? temp->random->next : temp -> random;
                }
                temp = temp -> next -> next ;
            }

            // step 4 : revert changes done in step 2
            originalNode = head;
            cloneNode = cloneHead;

            while(originalNode != NULL && cloneNode != NULL){
                originalNode -> next = cloneNode -> next;
                originalNode = originalNode -> next;

                if(originalNode != NULL){
                    cloneNode -> next = originalNode -> next;
                }
                cloneNode = cloneNode -> next;
            }            

            // step 5 : return ans
            return cloneHead;
        }
};



int main(){
    
    return 0;
}