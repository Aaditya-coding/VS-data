#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(){
        data = NULL;
        next = NULL;
    }

    public:
    Node(int x){
        data = x;
        next = NULL;
    }
};
class Solution{
    public:
    //Brute Force Solution
    //Time Complexity = O(n x 2(time complexity of map))
    //Space Complexity = O(n)
    int cycleStart(Node* head) {
        // code here
        if(head==NULL or head->next==NULL) return -1;
        Node* temp = head;
        map<Node*, int>mpp;
        while(temp!=NULL){
            mpp[temp]++;
            if(mpp[temp]>1){
                return temp->data;
                break;
            }
            temp = temp->next;
        }
        return -1;
    }
    //Optimal Solution - Tortoise and Hare Algorithm
    //As slow and fast collide, move slow to head
    //Time Complexity - O(n)
    //Space Complexity - O(1) 
    int cycleStart(Node* head) {
        // code here
        if(head==NULL or head->next==NULL) return -1;
        Node* slow = head; 
        Node* fast = head;
        int f=1;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow->data;
            }
        }
        return -1;
    }
};