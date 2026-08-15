#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    Node(){
        data = NULL;
        prev = NULL;
        next = NULL;
    }

    public:
    Node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }

    public:
    Node(int x, Node* p, Node* n){
        data = x;
        prev = p;
        next = n;
    }
};

class Solution{
    //Time Complexity = O(n)
    //Space Complexity = O(1)
    public:
    void deleteAllOccurOfX(struct Node** head, int x) {
        // code here
        Node* temp = *head;
        while(temp!=NULL){
            if(temp->data==x){
                if(temp == *head) *head = temp->next;
                
                Node* prevNode = temp->prev;
                Node* nextNode = temp->next;
                
                if(prevNode!=NULL) prevNode->next = nextNode;
                if(nextNode!=NULL) nextNode->prev = prevNode;
                
                delete temp;
                temp = nextNode;
            }
            else temp = temp->next;
        }
    }
};