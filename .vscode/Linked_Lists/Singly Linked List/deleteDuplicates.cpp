#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    Node():data(0),prev(NULL),next(NULL){}
    Node(int x):data(x),prev(NULL),next(NULL){}
    Node(int x, Node* p, Node* n):data(x),prev(p),next(n){}
};
class Solution {
  public:
    //Time Complexity = O(n)
    //Space Complexity = O(1)
    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node* temp = head;
        while(temp!=NULL and temp->next!=NULL){
            Node* nextNode = temp->next;
            while(nextNode!=NULL and temp->data == nextNode->data){
                Node* duplicate = nextNode;
                nextNode = nextNode->next;
                delete duplicate;
            }
            temp->next = nextNode;
            if(nextNode!=NULL) nextNode->prev = temp;
            temp = temp->next;
        }
        return head;
    }
};