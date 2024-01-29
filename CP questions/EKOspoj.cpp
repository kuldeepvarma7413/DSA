#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> trees, int x, int h){
    int totalWood=0;
    for(const int t:trees){
        if(t>h){
            totalWood+=t-h;
        }
    }
    return totalWood>=x;
}
int main() {
	// your code goes here
	long long int n=0;
    int x=0, maxi=0;
	cin>>n>>x;
	vector<int> trees(n);
	for(long long int i=0; i<n; i++){
        cin>>trees[i];
        if(maxi<trees[i]){
            maxi=trees[i];
        }
    }
	// logic to find sol
	int s=0, e=maxi, ans=0;;
	while(s<=e){
        int mid=s+(e-s)/2;
        if(check(trees,x,mid)){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    cout<<ans;
	return 0;
}