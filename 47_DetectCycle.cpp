#include<iostream>
#include<map>
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

bool detectLoop(Node* head){

    if(head == NULL){
        return false;
    }

    map<Node*, bool> visited;
    
    Node* temp = head;

    while(temp != NULL){

        if(visited[temp] == true){
            cout << "cycle is present on element : " << temp->data << endl;
            // this temp node is the beginning of the cycle 
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;

    }
    return false;
}

int main(){
    
    return 0;
}