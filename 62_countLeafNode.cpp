#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
  public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
    }
};
    


void inOrder(BinaryTreeNode<int>* root, int &count){
    // base case
    if(root == NULL){
        return ;
    }
    inOrder(root -> left, count); 
    
    //leaf node
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    
    inOrder(root -> right, count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    
    int cnt = 0;
    inOrder(root,cnt);
    return cnt;
}

int main(){
    
    return 0;
}