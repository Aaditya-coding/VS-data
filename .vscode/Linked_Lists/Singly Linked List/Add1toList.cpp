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
int helper(Node* head){
    Node* temp = head;
    if(temp==NULL)
        return 1;
    int carry = helper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data<10) return 0;
    temp->data = 0;
    return 1;
    }


Node* addOne(Node* head){
    if(head==NULL) return head;
    int carry = helper(head);
    if(carry==1){
        Node* newHead = new Node(carry);
        newHead->next = head;
        head = newHead;
        return head;
    }
    return head;
}