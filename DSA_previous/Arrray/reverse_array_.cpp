#include <iostream>
using namespace std;
void reverse(int A[],int n){
    int start=0,end=n-1;
	while(start<=end){
	   swap(A[start],A[end]);
	   start++;
	   end--;
	}
}
int main() {
    int t=0,n=0;
    cin>>t;
    while(t!=0){
        cin>>n;
        int arr[101];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        reverse(arr,n);
    	for(int i=0;i<n;i++){
  	        cout<<arr[i]<<" ";
	    }
        t--;
    }
}
