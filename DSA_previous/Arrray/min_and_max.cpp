#include<iostream>
using namespace std;

int findmin(int arr[],int n)
{
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        min=arr[i];
    }
    return min;
}
int findmax(int arr[],int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
    return max;
}

int main()
{
    int size;
    cout<<"Enter size of array ";
    cin>>size;
    int ar[100];
    for(int i=0;i<size;i++)
    {
        cin>>ar[i];
    }
    cout<<"minimum value is : "<<findmin(ar,size)<<endl;
    cout<<"maximum value is : "<<findmax(ar,size)<<endl;
}
