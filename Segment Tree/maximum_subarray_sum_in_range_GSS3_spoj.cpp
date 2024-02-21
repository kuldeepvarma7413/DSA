#include<bits/stdc++.h>
using namespace std;

class Node{    
public:
    int maxSum, preSum, sufSum, total;
    Node(){
        maxSum=INT_MIN;
        preSum=INT_MIN;
        sufSum=INT_MIN;
        total=INT_MIN;
    }
};

void buildTree(vector<int> &arr, vector<Node> &tree, int s, int e, int idx){
    if(s==e){
        tree[idx].total=arr[s];
        tree[idx].maxSum=arr[s];
        tree[idx].preSum=arr[s];
        tree[idx].sufSum=arr[s];
        return;
    }
    // call both sides (build both treesThank you.)
    int mid=s+(e-s)/2;
    buildTree(arr, tree, s, mid, idx*2);
    buildTree(arr, tree, mid+1, e, idx*2+1);
    // store val to parent node
    tree[idx].total= tree[idx*2].total + tree[idx*2+1].total; 
    tree[idx].sufSum= max( (tree[idx*2+1].total + tree[idx*2].sufSum)  , tree[idx*2+1].sufSum); 
    tree[idx].preSum= max( (tree[idx*2+1].preSum + tree[idx*2].total)  , tree[idx*2].preSum); 
    tree[idx].maxSum= max(tree[idx*2].maxSum , max( tree[idx*2+1].maxSum, tree[idx*2].sufSum+tree[idx*2+1].preSum ) ); 
    // return
    return;
}

Node query(vector<Node>& tree, int s, int e, int idx, int qs, int qe){
    // if query is out of range
    if(s>qe || e<qs){return Node();}
    // full overlap of qeury
    if(qs<=s && e<=qe){
        return tree[idx];
    }
    // call both sides
    int mid=s+(e-s)/2;
    Node left=query(tree, s, mid, idx*2, qs,qe);
    Node right=query(tree, mid+1, e, idx*2+1, qs,qe);
    cout<<" "<<left.maxSum<<" "<<right.maxSum<<endl;
    // create a node which contains maxsum of both
    Node n;
    n.total =left.total+right.total;
    n.sufSum=max( (left.sufSum+right.total), right.sufSum);
    n.preSum=max( (left.total+right.preSum), left.preSum);
    n.maxSum= max(left.maxSum, max( right.maxSum, left.sufSum+right.preSum ));
    return n;
}


int main(){
    vector<int> arr{0,1,2,-3,4};
    int n=arr.size();
    vector<Node> tree(4*n+1, Node());
    // tree built
    buildTree(arr, tree, 0, n-1, 1);
    // query now
    // find maxsum in range 0 to 2
    Node ans=query(tree, 0, n-1, 1, 2, 4);
    cout<<"maxsum: "<<ans.maxSum<<endl;
    cout<<"presum: "<<ans.preSum<<endl;
    cout<<"sufsum: "<<ans.sufSum<<endl;
    cout<<"total: "<<ans.total<<endl;
    return 0;
}

// done, just check for 0-3 query