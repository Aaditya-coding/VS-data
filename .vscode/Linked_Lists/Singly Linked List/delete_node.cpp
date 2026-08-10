#include <bits/stdc++.h>
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
        next = nullptr;
    }
};

     Node* deleteNode(Node* head, int x) {
        // code here
        if(head == NULL) return head;
        if(x == 1) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        Node* temp = head;
        Node* prev = NULL;
        int cnt = 1;
        while(temp!=NULL)
        {
            if(cnt>x) return head;
            if(cnt==x)
            {
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        return head;
    }
     Node* deletebyValue(Node* head, int val)
     {
        if(head == NULL) return head;
        Node* temp = head;
        Node* prev = NULL;
        if(head->data == val)
        {
            Node*temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while(temp!=NULL)
        {
            if(temp->data == val)
            {
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
     }

     Node* convertArr2LL(vector<int>arr)
     {
        Node* head = new Node(arr[0]);
        Node* mover = head;
        for(int i=1;i<arr.size();i++)
        {
            Node* temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
     }
     
     void printLL(Node* head)
     {
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<endl;
     }
     int main()
     {
        vector<int> arr = {2,9,10,12,16};
        cout<<"Enter the value: ";
        int x;
        cin>>x;
        Node* head  = convertArr2LL(arr);
        cout<<"BEFORE DELETION\n";
        printLL(head);
        head = deletebyValue(head,x);
        cout<<"AFTER DELETION\n";
        printLL(head);
     }
