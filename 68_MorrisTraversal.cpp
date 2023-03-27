#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void MorrisTraversal(Node* root){

    if(root == NULL)
        return;

    // current and predecessor
    Node *curr, *pre;
    curr = root;

    while(curr != NULL){

        if(curr->left == NULL){
            cout << curr->data <<" ";
            curr = curr->right;
        }

        else{
            // find inorder predecessor of current
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr){
                pre = pre->right;
            }

            // make curr as the right child of its inorder predecessor
            if(pre->right == NULL){
                pre->right = curr;
                curr = curr->left;
            }

            // revert the changes made in the if part to restorethe original tree
            else{
                pre->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
    
}

int main() 
{
    return 0;
}