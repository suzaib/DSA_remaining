#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data=data;
        }
};
Node* revLL(Node* head){
    if(!head || !head->next) return head;
    Node* temp=head;
    Node* prev=nullptr;
    while(temp){
        Node* front=temp->next;
        front->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

Node* addTwoRevLL(Node* head1,Node* head2){
    Node* curr1=head1;
    Node* curr2=head2;
    Node* newHead=new Node(-1);
    Node* curr=newHead;

    int carry=0;
    while(curr1 || curr2){
        int x=curr1? curr1->data : 0;
        int y=curr2? curr2->data : 0;
        int z=x+y+carry;
        if(z>9){
            z=z%10;
            carry=1;
        }
        else carry=0;
        Node* newNode=new Node(z);
        curr->next=newNode;
        curr=newNode;
        if(curr1) curr1=curr1->next;
        if(curr2) curr2=curr2->next;
    }
    if(carry==1){
        Node* newNode=new Node(carry);
        curr->next=newNode;
        curr=newNode;
    }
    Node* head=newHead->next;
    delete newHead;
    return head;
}
Node* add(Node* head1,Node* head2){
    if(!head1) return head2;
    if(!head2) return head1;
    head1=revLL(head1);
    head2=revLL(head2);
    Node* head=addTwoRevLL(head1,head2);
    head=revLL(head);
    return 0;
}
int main(){
    return 0;
}