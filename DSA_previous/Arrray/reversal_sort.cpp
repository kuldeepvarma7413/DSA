#include <iostream>
#include<vector>
using namespace std;

void reversalSort(vector<int> arr,int n, int x){
    int count=1;
     for(int i=0;i<n-1;i++){
	       if(arr[i]>arr[i+1]){
	           if(arr[i]+arr[i+1]>x){
	               count=0;
	               break;
	           }
	           else
	           swap(arr[i],arr[i+1]);
	       }
	}
	if(count==0)
	    cout<<"NO"<<endl;
	else
	    cout<<"YES"<<endl;
}

int main() {
	// your code goes here
	int t;
    cin>>t;
	while(t!=0){
        int n,x;
	    cin>>n;
	    cin>>x;
	    vector <int> arr;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    reversalSort(arr,n,x);
	    t--;
	}
	
	return 0;
}