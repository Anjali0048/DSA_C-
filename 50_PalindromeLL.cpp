#include<iostream>
#include<vector>
using namespace std;

class Node {

    public :
        int data;
        Node* next;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
};

class Solution{

    private :
        bool checkPalindrome(vector<int> arr){

            int n = arr.size();
            int s = 0;
            int e = n-1;

            while(s <= e){
                if(arr[s] != arr[e]){
                    return 0;
                }
                s++;
                e--;
            }
            return 1;
        }

    public :
        bool isPalindrome(Node* head){

            vector<int> arr;
            Node* temp = head;

            while(temp != NULL){
                arr.push_back(temp -> data);
                temp = temp -> next;
            }
            return checkPalindrome(arr);
        }
};


// approach 2 optimised since space complexity is O(n)

class Solution2{

    private :
        Node* getMid(Node* head){
            Node* slow = head;
            Node* fast = head -> next;

            while(fast != NULL && fast -> next != NULL){
                fast = fast -> next -> next;
                slow = slow -> next;
            }
            return slow;
        }
    
    Node* reverse(Node* head){
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public :
        bool isPalindrome(Node* head){

            if(head -> next == NULL){
                return true;
            }

            // step1 -> find middle
            Node* middle = getMid(head);

            // step2 -> reverse list after middle
            Node* temp = middle -> next;
            middle -> next = reverse(temp);

            // step3 -> compare both halves
            Node* head1 = head;
            Node* head2 = middle -> next;

            while(head2 != NULL){
                if(head1 -> data != head2 -> data){
                    return false;
                }
                head1 = head1 -> next;
                head2 = head2 -> next;
            }

            // step4(optional) -> repeat step2 to make the LL to its original form as we reversed the second half LL 
            temp = middle -> next;
            middle -> next = reverse(temp);

            return true;
        }

};


int main(){
    
    return 0;
}