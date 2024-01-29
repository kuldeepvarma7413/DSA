#include<iostream>
using namespace std;

void alternate(int arr[],int size)
{
    //swapping
    for(int i=0;i<size;i+=2){
        if(i+1<size){
            swap(arr[i],arr[i+1]);
        }
    }
    //printing in alternate function
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<ends;
    }
}

int main()
{
    //even array
    int a[6]={1,5,8,9,6};
    alternate(a,6);
    cout<<endl;
    
    //odd array
    int b[5]={4,8,9,6,4};
    alternate(b,5);

    return 0;
}