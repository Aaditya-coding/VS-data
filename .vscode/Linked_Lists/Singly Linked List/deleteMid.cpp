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
    //Time Complexity = O(3n/2)
    //Space Complexity = O(1)
    int lengthLL(Node* head){
        int length = 0;
        while(head!=NULL){
            length++;
            head = head->next;
        }
        return length;
    }
    Node* deleteMid(Node* head) {
        // Your Code Here
        if(head == NULL or head->next == NULL) return NULL;
        Node* temp = head;
        Node* prev = NULL;
        int mid = lengthLL(head)/2;
        for(int i=0;i<mid;i++){
            prev = temp;
            temp = temp->next;
        }
        Node* front = temp->next;
        prev->next = front;
        temp->next = NULL;
        delete temp;
        return head;
    }
    //Optimal Solution - Tortoise and Hare Algorithm
    //Time Complexity = O(n)
    //Space Complexity = O(1)
    Node* deleteMid(Node* head) {
        // Your Code Here
        if(head==NULL or head->next==NULL) return NULL;
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        while(fast!=NULL and fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* front = slow->next;
        prev->next = front;
        slow->next = NULL;
        delete slow;
        return head;
    }
};