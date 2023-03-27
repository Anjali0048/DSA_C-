#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void PreSucc(Node* root, Node* &pred, Node* &succ, int key){

    // base case 
    if(root == NULL)
        return ;
    
    if(root->data == key){

        // max value in left subtree is predecssor
        if(root->left != NULL){
            Node* temp = root->left;
            while(temp->right){
                temp = temp->right;
            }
            pred = temp;
        }

        // min value in right subtree is predecssor
        if(root->right != NULL){
            Node* temp = root->right;
            while(temp->left){
                temp = temp->left;
            }
            succ = temp;
        }
        return;
    }

    if(root->data > key){
        succ = root;
        PreSucc(root->left,pred,succ,key);
    }
    else{
        pred = root;
        PreSucc(root->right,pred,succ,key);
    }

}

int main(){
    
    return 0;
}