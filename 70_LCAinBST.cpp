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

Node* LCAinBST(Node* root, Node* P, Node* Q){
    
    while(root != NULL){

        if(root->data < P->data && root->data < Q->data){
            root = root->right;
        }

        else if(root->data > P->data && root->data > Q->data){
            root = root->left;
        }

        else{
            return root;
        }
    }
    
    // base case
    // if(root == NULL){
    //     return NULL;
    // }


    // if(root->data < P->data && root->data < Q->data){
    //     return LCAinBST(root->right,P,Q);
    // }

    // if(root->data > P->data && root->data > Q->data){
    //     return LCAinBST(root->left,P,Q);
    // }

    // else when root->data > a && root->data < b and vice versa
    // because the root is the LCA in else case
    // return root;
}


int main(){
    return 0;
}