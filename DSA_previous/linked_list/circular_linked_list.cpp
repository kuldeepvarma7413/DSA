#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//insert
void insertinto(Node* &head, int pos, int val) {
    // Write your code here
    if(pos==0){
        Node* newnode=new Node(val);
        newnode->next=head;
        head=newnode;
        //cout<<head;
        return;
    }
    else{
        Node* temp=head;
        int count=0;
        while(count<pos-1){
            temp=temp->next;
            count++;
        }

        Node* newnode=new Node(val);
        newnode->next=temp->next;
        temp->next=newnode;
        //cout<<head;
    }
}


Node* deleteNode(Node* &head, int key)
{
    // Write your code here.
    if(head==NULL){
        return head;
    }

    Node* prev=head;
    Node* temp=prev->next;
    while(temp->data!=key && temp!=head){
        prev=temp;
        temp=temp->next;
    }
    ///////////////////////////////return -1
    if(temp->data!=key){
        return head;
    }
    prev->next=temp->next;
    if(temp==prev){
        head=NULL;
    }
    else if(head==temp){
        head=temp->next;
    }
    temp->next=NULL;
    delete temp;
    return head;
}


//print
//print element of Linked List
void printlist(Node* &head){
    Node* temp=head;

    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}

int main(){
    //circular list
    Node *head=new Node(10);
    //Node *tail=NULL;
    head->next=head;

    insertinto(head,1,10);
    insertinto(head,2,20);
    insertinto(head,3,30);
    printlist(head);
    deleteNode(head,20);
    printlist(head);

    return 0;
}
