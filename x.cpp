#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

     public:
    Node(int data1,Node* next1)
    {
        data=data1;
        next=next1;

    }
    public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;

    }
};

Node* solve(vector<int>&arr)
{
    Node* head=new Node(arr[0]);
    Node* move=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp= new Node(arr[i]);
        move->next=temp;
        move=temp;
        // move=move->next;

    }
    return head;
}
int length(Node* head)
{
    int c=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    return c;
}
Node* remove(Node* head)
{
    if(head==NULL)
    return head;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node* remove1(Node* head)
{
    if(head==NULL || head->next==NULL)
    return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
Node* last(Node* head,int val)
{
    if(head==NULL)
    return new Node(val);

    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=new Node(val);
    return head;

}
Node* middle(Node*head,int el,int k)
{
    if(head==NULL)
    {
        if(k==1)
        return new Node(el);
    }
    if(k==1)
    return new Node(el,head);

    Node* temp=head;
    int c=0;
    while(temp!=NULL)
    {
c++;
if(c==k-1)
{
    Node* x=new Node(el);
    x->next=temp->next;
    temp->next=x;
    break;
}
temp=temp->next;

    }
    return head;
    
}
void print(Node* head)
{
Node *temp=head;
while(temp!=NULL)
{
    cout<<temp->data<<" ";
    temp=temp->next;
}
}
int main() {
vector<int>arr={10,5,8,7,9,19,11};

Node *head=solve(arr);
// cout<<head->data<<endl;

// Node *temp=head;
// while(temp!=NULL)
// {
//     cout<<temp->data<<" ";
//     temp=temp->next;
// }
// int k=length(head);
// cout<<k<<endl;

// head=remove1(head);
head=middle(head,1001,3);
print(head);


}