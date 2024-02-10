#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int height(TreeNode* root, int& mini){
    if(root==nullptr){return 0;}

    int leftH=height(root->left, mini);
    int rightH=height(root->right, mini);

    mini=max(mini, abs(leftH-rightH));
    return 1+max(leftH, rightH);
}

bool isBalanced(TreeNode* root){
    int mini=0;
    int ans=height(root, mini);
    return (mini<=1 ? true : false);
}

int main(){
    TreeNode* root6=new TreeNode(7, nullptr, nullptr);
    TreeNode* root5=new TreeNode(15, nullptr, nullptr);
    TreeNode* root2=new TreeNode(20, root5, root6);
    TreeNode* root1=new TreeNode(9, nullptr, nullptr);
    TreeNode* root=new TreeNode(3, root1, root2);
    int ans=isBalanced(root);
    if(ans){cout<<"Balanced";}
    else{cout<<"Not balanced";}
    return 0;
}