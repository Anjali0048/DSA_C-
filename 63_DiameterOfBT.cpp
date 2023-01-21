#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution {
  public:

    // int height(Node* root){
        
    //     if(root == NULL)
    //         return 0;
            
    //     int left = height(root->left);
    //     int right = height(root->right);
    //     int ans = max(left, right) + 1;
    //     return ans;
    // }

    // int diameter(Node* root) {
    //     // Your code here
    //     if(root == NULL)
    //         return 0;
            
    //     int op1 = diameter(root->left);
    //     int op2 = diameter(root->right);
    //     int op3 = height(root->left) + 1 + height(root->right);
    //     int ans = max(op1, max(op2,op3));
    //     return ans;
    // }

    // optimised solution

    pair<int,int> diameterFast(Node* root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);         
            return p;
        }    
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int,int> ans;
        ans.first = max(op1, max(op2,op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
    
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};

int main() {
    
    return 0;
}