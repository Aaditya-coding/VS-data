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
    //Time Complexity = O(n x 2logn)
    //Space Complexity = O(n)
    bool detectLoop(Node* head){
        if(head==NULL) return false;
        map<Node*, int>mpp;
        Node* temp = head;
        while(temp!=NULL){
            if(mpp[temp]==1) return true;
            mpp[temp] = 1;
            temp = temp->next;
        }
        return false;
    }

    //Optimal Solution - Tortoise and Hare Algorithm
    //Time Complexity = O(n)
    //Space Complexity = O(1)
    bool detectCycle(Node* head) {
        // code here
        if(head==NULL) return false;
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};