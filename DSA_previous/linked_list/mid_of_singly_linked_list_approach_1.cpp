#include<iostream>
using namespace std;

//creating Node
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

//insert element at head
void insertAthead(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}

//print element of Linked List
void print(Node* &head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void printMid(Node* &mid){
    cout<<mid->data<<endl;
}


Node* findMid(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    if(head->next->next==NULL){
        return head->next;
    }

    Node* fast=head;
    Node* slow=fast;

    while(fast!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}


int main(){

    //creating 1st Node
    Node* node1=new Node(20);
    Node* head=node1;
    Node* tail=node1;

    //insert at starting
    insertAthead(head,30);
    print(head);

    insertAthead(head,40);
    print(head);

    insertAthead(head,50);
    print(head);

    Node* mid=findMid(head);
    printMid(mid);

    //time complexity O(n)
    //Space complexity O(1)

    return 0;
}
