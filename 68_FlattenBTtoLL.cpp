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

class Solution
{
    public:
    void flatten(Node *root)
    {
        Node *curr = root;
        while(curr != NULL){
            
            if(curr->left){
                Node *pred = curr->left;
                while(pred->right)
                    pred = pred->right;
                    
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

int main(){
    return 0;
}