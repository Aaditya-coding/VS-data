#include<bits/stdc++.h>
using namespace std;

struct Node
{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }

    public:
    Node(int data2, Node* next2)
    {
        data = data2;
        next = next2;
    }
};

Node* revLL(Node* head)
    {
        stack<int>st;
        Node* temp = head;
        while(temp!=NULL)
        {
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL)
        {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
    
    Node* dltinitial0(Node* head)
    {
        Node* temp = head;
        while(temp!=NULL and temp->data==0)
        {
            if(temp->data == 0)
            {
                Node* dlt = temp;
                temp = temp->next;
                dlt->next = NULL;
                delete dlt;
            }
            else
            temp = temp->next;
        }
        head = temp;
        return head;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        if(head1 == NULL) return head2;
        else if(head2 == NULL) return head1;
        else
        {
            head1 = revLL(head1);
            head2 = revLL(head2);
            Node* t1 = head1;
            Node* t2 = head2;
            Node* dummyNode = new Node(-1);
            Node* curr = dummyNode;
            int carry = 0;
            while(t1!=NULL or t2!=NULL)
            {
                int sum = carry;
                if(t1) sum = sum+t1->data;
                if(t2) sum = sum+t2->data;
                carry = sum/10;
                Node* newNode = new Node(sum%10);
                curr->next = newNode;
                curr = curr->next;
                if(t1)t1=t1->next;
                if(t2)t2=t2->next;
            }
            if(carry) 
            {
                Node* newN = new Node(carry);
                curr->next = newN;
            }
            Node* res = dummyNode->next;
            res = revLL(res);
            res = dltinitial0(res);
            return res;
        }
    }