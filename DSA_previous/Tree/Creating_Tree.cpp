#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};
Node *root=NULL,*loc=NULL,*par=NULL;

//finding element in tree
void finding(int item){
    Node *ptr,*parptr;
    if(root==NULL){
        loc=NULL;
        par=NULL;
        return;
    }
    if(root->data==item){
        loc=root;
        par=NULL;
        return;
    }
    if(root->data>item){
        ptr=root->right;
        parptr=root;
    }
    else{
        ptr=root->right;
        parptr=root;
    }

    while(ptr!=NULL){
        if(ptr->data==item){
            loc=ptr;
            par=parptr;
            return;
        }
        if(ptr->data>item){
            parptr=ptr;
            ptr=ptr->left;
        }
        else{
            parptr=ptr;
            ptr=ptr->right;
        }
    }

    loc=NULL;
    par=parptr;
}

//creating tree
void insert(int item){
    finding(item);
    if(loc!=NULL){
        cout<<item<<" is already there"<<endl;
        return;
    }
    Node *newnode=new Node;
    newnode->data=item;
    newnode->left=NULL;
    newnode->right=NULL;

    //if parent is there
    if(par!=NULL){
        if(par->data>item){
            par->left=newnode;
        }
        else{
            par->right=newnode;
        }
    }
    else{
        root=newnode;
    }
}

//printing
void preorder(Node *r){
    if(r!=NULL){
        cout<<r->data<<" ";
        preorder(r->left);
        preorder(r->right);
    }
}

//case A for deleting
void caseA(int item,Node *l, Node *p){
    Node *child=NULL;
    if(l->left!=NULL){
        child=l->left;
    }
    if(l->right!=NULL){
        child=l->right;
    }
    else{
        child=NULL;
    }
    if(p!=NULL){
        if(l==p->left){
            p->left=child;
        }
        else{
            p->right=child;
        }
    }
    else{
        root=child;
    }
}

//case b for deleting
void caseB(int item,Node *l,Node *p){
    Node *ptr,*parptr;
    ptr=l->right;
    parptr=l;
    while(ptr->left!=NULL){
        parptr=ptr;
        ptr=ptr->left;
    }
    Node *ptr1=ptr,*parptr1=parptr;
    caseA(ptr1->data,ptr1,parptr);
    if(p!=NULL){
        if(p->left==l){
            p->left=ptr;
        }
        else{
            p->right=ptr;
        }
    }
    else{
        root=ptr;
        ptr->left=l->left;
        ptr->right=l->right;
    }
}

//deleting function
void deleting(int item){
    finding(item);
    if(loc==NULL){
        cout<<item<<" is not available in the tree"<<endl;
    }
    if(loc->left!=NULL && loc->right!=NULL){
        caseB(item,loc,par);
    }
    else{
        caseA(item,loc,par);
    }
}

int main(){
    insert(26);
    insert(40);
    insert(10);
    insert(47);
    insert(30);
    insert(76);

    //preorder printing
    preorder(root);
    cout<<endl;

    //deleting item from tree
    deleting(26);

    //preorder printing
    preorder(root);
    cout<<endl;

    //deleting item from tree
    deleting(47);

    //preorder printing
    preorder(root);
    cout<<endl;

    return 0;
}
