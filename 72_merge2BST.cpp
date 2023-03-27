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

void inorder(TreeNode<int> *root, vector<int> &in){
    if(root == NULL)
        return;
    
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b){
    vector<int> ans(a.size() + b.size());
    int i=0, j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i];
        }
        else{
            ans[k++] = b[j++];
        }
    }

    while(i<a.size()){
        ans[k++] = a[i++];
    }

    while(i<b.size()){
        ans[k++] = a[j++];
    }
    return ans;
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> &in){
    // base case
    if(s<e)
        return NULL;

    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST(mid+1, e, in);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1,TreeNode<int> *root2){

    // step 1: store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // step 2 : merge both sorted arrays
    vector<int> mergeArray = mergeArrays(bst1,bst2);

    // step 3 : use merged inorder array to build BST
    int s=0, e=mergeArrays.size()-1;
    return inorderToBST(s,e,mergeArrays);

}

int main(){
    
    return 0;
}