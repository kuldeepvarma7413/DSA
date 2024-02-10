#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        data=data;
        left=right=NULL;
    }
};
Node* buildTree(vector<int> &arr, int s, int e){
    if(s>e){return NULL;}
    if(arr[s]==-1){return NULL;}

    Node* root=new Node(arr[s]);
    cout<<arr[s]<<" ";
    root->left=buildTree(arr, s+1,e);
    root->right=buildTree(arr, s+1,e);
    return root;
}
void printTree(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
    return;
}
int main(){
    vector<int> arr{1, 2, 3, -1, -1, 4, -1, -1, 5, -1, -1};
    int e=arr.size()-1;
    Node* root=buildTree(arr, 0,e);
    cout<<endl;
    printTree(root);
    return 0;
}

look into it