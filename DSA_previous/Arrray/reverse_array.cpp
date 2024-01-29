#include<iostream>
using namespace std;

void reverse(int arr[],int size)
{
    int start=0,end=size-1;
    while(start<=end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void printarray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<ends;
    }
}

int main()
{
    int arr[6]={1,5,6,8,4,2};
    int array[5]={4,8,9,6,7};

    reverse(arr,6);
    cout<<endl;
    reverse(array,5);
    cout<<endl;

    printarray(arr,6);
    cout<<endl;
    printarray(array,5);
    cout<<endl;
}