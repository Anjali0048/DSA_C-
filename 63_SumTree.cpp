#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution
{
    public:
    
    pair<bool,int> isSumTreeFast(Node* root){
        
        // base case
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        if(root->left == NULL && root->right == NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        bool condn = root->data == leftAns.second + rightAns.second;
        
        pair<bool,int> ans;
        
        if(left && right && condn){
            ans.first = true;
            ans.second = root->data + leftSum + rightSum;
        }
        else{
            ans.first = false;
        }
        return ans;
        
    }
    
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};

int main(){
    
    return 0;
}