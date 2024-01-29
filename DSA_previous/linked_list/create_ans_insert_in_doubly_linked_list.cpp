#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
        int value=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory is free now for node which had data "<<value<<endl;
    }
};

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &tail,Node* &head,int data){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=head;
    }
    else{
        Node* temp=new Node(data);
        temp->next=head;
        temp->prev=NULL;
        head=temp;
    }
}

void insertAtTail(Node* &tail,Node* &head,int data){
    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        head=temp;
    }
    else{
        Node* temp=new Node(data);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void insertAtPosition(Node* &tail,Node* &head,int position,int data){
    if(position==1){
        insertAtHead(tail,head,data);
        return;
    }

    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }

    if(temp->next==NULL){
        insertAtTail(tail,head,data);
        return;
    }

    //creating node to insert
    Node* insertAt=new Node(data);

    insertAt->next=temp->next;
    insertAt->next->prev=insertAt;
    temp->next=insertAt;
    insertAt->prev=temp;
}

////////////////////////////////////////
//deleting an element at specific position
void deleteAtPosition(Node* tail,Node* &head,int position){

    if(position==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return;
    }

    else{
        Node* curr=head;
        Node* prev=NULL;

        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }
////set the tail when we delete last node of linked lisr
        /*if(curr->next=NULL){
            tail=curr;
        }*/

        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        prev->next=NULL;
        tail=prev;
        delete curr;

        //no need to change head otherwise it will print elements after deletion
    }
}
/////////////////////////////////////////////

int main() {
    //creating doubly Linked List
    //Node* node1=new Node(20);
    //Node* head=node1;
    //Node* tail=node1;

    //when list is empty
    Node* head=NULL;
    Node* tail=NULL;

    print(head);

    insertAtHead(tail,head,10);
    print(head);

    insertAtTail(tail,head,30);
    print(head);

    insertAtTail(tail,head,40);
    print(head);

    insertAtPosition(tail,head,3,5);
    print(head);
    cout<<"tail "<<tail->data<<endl;

    deleteAtPosition(tail,head,4);
    print(head);
    cout<<"tail "<<tail->data<<endl;

    return 0;
}
