#include <bits/stdc++.h>
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
        next = nullptr;
    }

    public:
    Node(int data2, Node* next2)
    {
        data = data2;
        next = next2;
    }
};

Node* convertarr2LL(vector<int> arr)
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
}

Node* addtail(Node* head, int val)
{
    Node* temp = head;
    Node* tail = new Node(val);
    while(temp!=NULL)
    {
        if(temp->next == NULL)
        {
            temp->next = tail;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector <int> arr = {2,9,12,16};
    int x;
    cout<<"Enter the value you want to add"<<endl;
    cin>>x;
    Node* head = convertarr2LL(arr);
    cout<<"BEFORE: \n";
    printLL(head);
    addtail(head,x);
    cout<<"AFTER: \n";
    printLL(head);
}
