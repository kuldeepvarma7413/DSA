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


//reversing linked list
node* reverse_linked_list(node* &head){
    //basecase
    if(head==NULL || head->next==NULL){
        return head;
    }

    //processing
    node* temp=reverse_linked_list(head->next);

    head->next->next=head;
    head->next=NULL;

    return temp;

}


int main(){

    //creating 1st node
    node* node1=new node(20);
    node* head=node1;
    node* tail=node1;

    //insert at starting
    insertAthead(head,30);
    print(head);

    insertAthead(head,40);
    print(head);

    insertAthead(head,50);
    print(head);

    head=reverse_linked_list(head);
    print(head);

    //time complexity O(n)
    //space complexity O(n)

    return 0;
}
