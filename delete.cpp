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
Node* add(Node* head1,Node* head2){
    if(!head1) return head2;
    if(!head2) return head1;
    string s1;
    Node* curr1=head1;
    while(curr1){
        s1+=('0'+curr1->data);
        curr1=curr1->next;
    }

    string s2;
    Node* curr2=head2;
    while(curr2){
        s2+=('0'+curr2->data);
        curr2=curr2->next;
    }
    int x=stoi(s1);
    int y=stoi(s2);
    int z=x+y;
    string s=to_string(z);
    Node* head=new Node(s[0]-'0');
    Node* curr=head;
    Node* newNode;
    for(int i=1;i<s.size();i++){
        newNode=new Node(s[i]-'0');
        curr->next=newNode;
    }

}
int main(){
    return 0;
}