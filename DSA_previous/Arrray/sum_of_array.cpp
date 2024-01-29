#include<iostream>
using namespace std;

void sum(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    cout<<endl<<"Sum of array is : "<<sum<<endl;
}

int main()
{
    int size;
    int arr[20];
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    sum(arr,size);

    return 0;
}