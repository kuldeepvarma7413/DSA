#include<iostream>
using namespace std;

bool search(int arr[],int size,int n){
    for(int i=0;i<size;i++){
        if(arr[i]==n){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int value,size=10;
    int arr[10]={1,5,6,8,2,1,5,6,-9,6};
    value=8;
    if(search(arr,size,value))
    {
        cout<<"Value found";
    }
    else
    cout<<"Value not found";
    return 0;
}