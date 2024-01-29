#include <bits/stdc++.h>
using namespace std;


static bool cmp(pair<int,int>a,pair<int,int>b){
	return a.first > b.first;
} 
int main() {
	
	int t;
	cin >>t;
	while(t--){
		int stops;
		cin>>stops;
		vector<pair<int,int>>arr;
		for(int i = 0 ; i < stops;i++){
			int data1,data2;
			cin>>data1>>data2;
			arr.push_back({data1,data2});
		}
		int last,refill;
		cin>>last>>refill;
		sort(arr.begin(),arr.end(),cmp);
		int cnt = 0;
		for(int i = 0 ; i < stops;i++){
		      int left = refill - (last - arr[i].first);
		      refill = refill + arr[i].second;
		      last = arr[i].first;
		     
		      if(last <= refill){
		      	break;
		      }
		       cnt++;
		}
		cout<<cnt<<"\n";
	}
	

	return 0;
}

// done