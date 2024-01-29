#include<iostream>
using namespace std;

void findunique(int arr[],int size)
{
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];    //xor operation gives 0 for same inputs
    }
    cout<<"Unique element is : "<<ans<<endl;
}

int main()
{
    int a[7]={4,9,4,9,6,3,6};
    findunique(a,7);

    return 0;
}