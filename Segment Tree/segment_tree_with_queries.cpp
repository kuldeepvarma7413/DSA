#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<int>& arr, vector<int>& tree, int s, int e, int idx){
	if(s==e){
		tree[idx]=arr[s];
		return;
	}
	// mid
	int mid=s+(e-s)/2;
	// build left right tree
	buildTree(arr, tree, s, mid, idx*2);
	buildTree(arr, tree, mid+1, e, idx*2+1);
	// fill tree arr with min
	tree[idx]=min(tree[idx*2], tree[idx*2+1]);
	return;
}

int query(vector<int>& tree, int s, int e, int idx, int qs, int qe){
	// base case
	if(s>qe || e<qs){return INT_MAX;}
	// complete overlap
	if(qs<=s && e<=qe){
		return tree[idx];
	}
	// call both sides

	int mid=s+(e-s)/2;
	int L=query(tree, s, mid, idx*2, qs, qe);
	int R=query(tree, mid+1, e, idx*2+1, qs, qe);
	return min(L,R);
}
// tree, start, end, tree curr idx, idx to be updated, val to be kept on update idx
void update(vector<int>& tree, int s, int e, int idx, int i, int val){
	// if index doesn't lie in range
	if(i<s || i>e){return;}
	// if we reach leaf node
	if(s==e){
		tree[idx]=val;
		return;
	}
	// call both sides
	int mid=s+(e-s)/2;
	update(tree, s, mid, idx*2, i, val);
	update(tree, mid+1, e, idx*2+1, i, val);
	tree[idx]=min(tree[idx*2], tree[idx*2+1]);
	return;
}

int main() {
	int n, q;
	cin>>n>>q;
	vector<int> arr(n+1,0);
	vector<int> tree(4*n+1);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	// build tree
	buildTree(arr, tree, 0, n-1, 1);
	// for(auto a: tree){
	// 	cout<<a<<" ";
	// }
	// read queries
	for(int i=0; i<q; i++){
		char op;
		int qs,qe;
		cin>>op>>qs>>qe;
		if(op=='q'){
			cout<<query(tree, 0, n-1, 1, qs-1, qe-1)<<endl;
		}else{
			update(tree, 0, n-1, 1, qs-1, qe);
		}
	}
	return 0;
}

//  input
// 5 5
// 1 5 2 4 3
// q 1 5
// q 1 3
// q 3 5
// u 3 6
// q 1 5

// output:
// 1
// 1
// 2
// 1

// done