#include<bits/stdc++.h>
using namespace std;

struct Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1)
    {
        data = data1;
        next = next1;
    }

    public:
    Node(int data2)
    {
        data = data2;
        next = NULL;
    }
  
};

class solution {
public:
    int lengthLL(Node* head)
    {
        int cnt = 0;
        while(head!=NULL)
        {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    Node* addAtTail(Node* head, int data)
    {
        Node* temp = head;
        Node* newTail = new Node(data);
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newTail;
        return head;
    }
    Node* addAtHead(Node* head, int data)
    {
        Node* newHead = new Node(data);
        newHead->next = head;
        head = newHead;
        return head;
    }
    Node* insertionAtKthPosition(Node* head, int k, int data) {
        //Write your code here...
        if(head==NULL) return NULL;
        else
        {
            if(k==0) addAtHead(head,data);
            else if(k==(lengthLL(head))) addAtTail(head,data);
            else if(k>(lengthLL(head))) return head;
            else
            {
                int cnt=0;
                Node* temp = head;
                Node* prev = NULL;
                Node* newNode = new Node(data);
                while(temp!=NULL)
                {
                    if(cnt==k)
                    {
                        newNode->next = temp;
                        prev->next = newNode;
                    }
                    cnt++;
                    prev = temp;
                    temp = temp->next;
                }
                return head;
            }
        }
        
    }

};