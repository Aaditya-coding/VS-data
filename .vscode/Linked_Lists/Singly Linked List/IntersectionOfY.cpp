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
    //Normal Solution
    //Time Complexity = O(N1 + 2N2)
    int lengthLL(Node* head){
        int length = 0;
        while(head!=NULL){
            length++;
            head = head->next;
        }
        return length;
    }
    Node* intersectPoint(Node* head1, Node* head2){
        if(head1==NULL or head2==NULL) return NULL;
        int diff = abs(lengthLL(head1)-lengthLL(head2));
        Node* t1 = head1;
        Node* t2 = head2;
        if(lengthLL(head1)>lengthLL(head2)){
            for(int i=0;i<diff;i++) t1 = t1->next;
            while(t1!=NULL and t2!=NULL)
            {
            if(t1==t2) return t2;
            t1=t1->next;
            t2=t2->next;
            }
        }
        else{
            for(int i=0;i<diff;i++) t2 = t2->next;
            while(t1!=NULL and t2!=NULL)
            {
            if(t1==t2) return t2;
            t1=t1->next;
            t2=t2->next;
            }
        }
        return NULL;
    }

    //Optimal Solution
    //Time Complexity = O(n1+n2)
    Node* findIntersection(Node* head1, Node* head2){
        if(head1==NULL or head2==NULL) return NULL;
        Node* t1 = head1;
        Node* t2 = head2;
        while(t1!=t2){
            t1 = t1->next;
            t2 = t2->next;
            if(t1==NULL) t1 = head2;
            if(t2==NULL) t2 = head1;
        }
        if(t1==t2) return t1;
        return NULL;
    }
};