#include<bits/stdc++.h>
using namespace std;

// binary number will contain only 0 and 1 so every node will have only two pointers,
// 0 for left node and 1 for right node and we dont have to store 0 and 1

// we can store too

class Node{
public:
    Node* left;
    Node* right;
};

class Trie{
    // construct main root
    Node* root;
public:
    Trie(){
        root= new Node();
    }

    void insert(int n){
        // fetch root node
        Node* temp=root;
        // left to right traversal in bits
        for(int i=31; i>=0; i--){
            int bit= (n>>i)&1;
            // if bit is 0
            if(bit==0){
                // if 0 is present
                if(temp->left!=NULL){
                    temp=temp->left;
                }
                // if 0 is not present
                else{
                    temp->left=new Node();
                }
            }
            // if bit is 1
            else{
                // if 1 is present
                if(temp->right!=NULL){
                    temp=temp->right;
                }
                // if 1 is not present
                else{
                    temp->right=new Node();
                }
            }
        }
    }

    int maxXOR(int n){
        // fetch root node
        Node* temp=root;
        int val=0;
        cout<<endl;
        // find inverted bit for each bit if possible
        for(int i=31; i>0; i--){
            int bit= (n>>i)&1;
            cout<<i<<" ";
            // if bit is 0
            if(bit == 1){
                // find if inverted bit 1 is present
                if(temp->right!=NULL){
                    val+=(1<<i);
                    temp=temp->right;
                }else{
                    temp=temp->left;
                }
            }
            // if bit is 1
            else{
                // find if inverted (0) bit is present
                if(temp->left!=NULL){
                    val+=(1<<i);
                    temp=temp->left;
                }else{
                    temp=temp->right;
                }
            }
        }
        // found val, return xor
        cout<<endl<<val<<" "<<n<<endl;
        return n^val;
    }


};

int main(){
    int arr[]={3,10,5,25,9,2};
    int ans=INT_MIN;
    Trie t;
    for(const int a: arr){
        t.insert(a);
    }
    for(const int a: arr){
        int temp=t.maxXOR(a);
        ans=max(ans, temp);
    }
    cout<<ans;
    return 0;
}