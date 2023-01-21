#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution{
    public:
    
    pair<bool,int> isBalanceFast(Node* root){
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        pair<int,int> left = isBalanceFast(root->left);
        pair<int,int> right = isBalanceFast(root->right);
        
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second)  <= 1;
        
        pair<bool,int> ans ;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalanceFast(root).first;
    }
};

int main(){
    
    return 0;
}