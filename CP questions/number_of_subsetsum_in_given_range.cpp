// Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN (-20,000,000 ≤ Si ≤ 20,000,000), determine how many subsets of S (including the empty one) have a sum between A and B (-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.

// Input
// The first line of standard input contains the three integers N, A, and B. The following N lines contain S1 through SN, in order.

// Output
// Print a single integer to standard output representing the number of subsets satisfying the above property. Note that the answer may overflow a 32-bit integer.

// Example
// Input:
// 3 -1 2
// 1
// -2
// 3

// Output:
// 5

#include <bits/stdc++.h>
#include<vector>
using namespace std;

void findSubsetSum(vector<int> &arr,vector<int> &s,int n, int start){
	for(int i=0; i<(1<<n); i++){
        int j=start+0, val=i;
        long long int sum=0;
        while(val>0){
            if(val&1){sum+=arr[j];}
            j++;
            val=val>>1;
        }
        s.push_back(sum);
    } 
}

int main() {
	// your code goes here
	int n,a,b;
	vector<int> s;
	cin>>n>>a>>b;
	for(int i=0; i<n; i++){int a=0;cin>>a; s.push_back(a);};
	
	vector<int> subsetsum1;
	vector<int> subsetsum2;
    findSubsetSum(s,subsetsum1, n/2, 0);
    findSubsetSum(s,subsetsum2, (n-(n/2)), n/2);
    
    // sort 2nd subsetarr
    sort(subsetsum2.begin(), subsetsum2.end());

    long long int count=0;
    for(const int x:subsetsum1){
        int i1=lower_bound(subsetsum2.begin(), subsetsum2.end(), a-x)-subsetsum2.begin();
        int i2=upper_bound(subsetsum2.begin(), subsetsum2.end(), b-x)-subsetsum2.begin();
        count+=i2-i1;
    }
    cout<<count;	
	
	return 0;
}
