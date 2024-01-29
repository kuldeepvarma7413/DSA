#include<iostream>
using namespace std;

int findSum(int arr[],int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){
    int n;
    cout<<"Enter number of elements (number<=100): ";
    cin>>n;
    int arr[100];
    for(int i=0; i<n; i++){
        cin>>arr[n];
    }
    cout<<"Sum is: "<<findSum(arr, n);
    return 0;
}