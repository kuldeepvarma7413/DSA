#include<iostream>
using namespace std;

//creating node
class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~node(){
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

//insert element at head
void insertAthead(node* &head,int data){
    node* temp=new node(data);
    temp->next=head;
    head=temp;
}

//print element of Linked List
void print(node* &head){
    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//insert element at tail
void insertAtTail(node* &tail,int data){
    node* temp=new node(data);
    tail->next=temp;
    tail=temp;
}

//insert element at specific position
void insertAtPosition(node* &tail, node* &head,int position,int data){
    //if position is 1
    if(position==1){
        insertAthead(head,data);
        return ;
    }

    //triversing the linked list to reach at position
    node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }

    //when position is last
    if(temp->next==NULL){
        insertAtTail(tail,data);
        return ;
    }

    //creating node to add at specific position
    node* InsertAt=new node(data);
    InsertAt->next=temp->next;
    temp->next=InsertAt;
}

//deleting an element at specific position
void deleteAtPosition(node* tail,node* &head,int position){

    if(position==1){
        node* temp=head;
        head=temp->next;
        temp->next=NULL;
        return;
    }

    else{
        node* temp=head;
        int count=1;
        while(count<position-1){
            temp=temp->next;
            count++;
        }

        if(temp->next=NULL){
            tail=temp->next;
        }

        node* temporary=temp->next;
        temp->next=temporary->next;
        temporary->next=NULL;
        delete temporary;

        //no need to change head otherwise it will print elements after deletion
    }
}

int main(){

    //creating 1st node
    node* node1=new node(20);
    node* head=node1;
    node* tail=node1;

    //insert at starting
    insertAthead(head,30);
    print(head);

    //insert at end
    insertAtTail(tail,50);
    print(head);

    //insert at specific position
    insertAtPosition(tail,head,3,70);
    print(head);

    deleteAtPosition(tail,head,1);
    print(head);


    return 0;
}
