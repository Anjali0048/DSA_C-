#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class TreeNode
{
public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

void convertIntoSortedDLL(TreeNode<int> *root, TreeNode<int>* &head){
    // base case
    if(root == NULL)
        return NULL;

    convertIntoSortedDLL(root->right, head);
    root->right = head;
     
    if(head != NULL)    
        head -> left = root;

    head = root;

    convertIntoSortedDLL(root->left, head); 
}

TreeNode<int>* mergeLL(TreeNode<int> *head1, TreeNode<int> *head2){

    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){

            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail -> right = head1;
                head1 -> left = tail;
                tail = head1;
                head1 = head1 -> right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head1 = head2->right;
            }
            else{
                tail -> right = head2;
                head2 -> left = tail;
                tail = head2;
                head2 = head2 -> right;
            }
        }
    }
    while(head1 != NULL){
        tail -> right = head1;
        head1 -> left = tail;
        tail = head1;
        head1 = head1 -> right;
    }
    while(head2 != NULL){
        tail -> right = head2;
        head2 -> left = tail;
        tail = head2;
        head2 = head2 -> right;        
    }
    return head;

}

int countNodes(TreeNode<int> *head){
    int cnt = 0;
    TreeNode<int> *temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp -> right;
    }
    return cnt;
}

TreeNode<int> *sortedLLtoBST(TreeNode<int>* &head, int n){

    // base case
    if(n <= 0 || head == NULL)
        return NULL;
    
    TreeNode<int> *left = sortedLLtoBST(head, n/2);

    TreeNode<int> *root = head;

    root -> left = left;

    head = head -> next;

    root -> right = sortedLLtoBST(head, n-n/2-1);
    return root;

}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){

    // step 1 : convert BST into sorted LL
    TreeNode<int> *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1 -> left = NULL;

    TreeNode<int> *head2 = NULL;
    convertIntoSortedDLL(root2, head1);
    head2 -> left = NULL;

    // step 2 : merge sortes LL
    TreeNode<int> *head = mergeLL(head1, head2);

    // step 3 : convert SLL int BST
    return sortedLLtoBST(head, countNodes(head));
}

int main(){
    
    return 0;
} 