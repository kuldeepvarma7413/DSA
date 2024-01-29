#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    //input
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //insertation sort
    for(int i=1;i<n;i++){
        int temp;
        temp=arr[j]
        while(j>0 && arr[i]>temp){
            arr[i+1]=arr[i];
            i--;
        }
    }

    //print
    for(int i=0;i<n;i++){
        cout>>arr[i];
    }
    
}