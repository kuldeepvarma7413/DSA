#include<bits/stdc++.h>
using namespace std;
int getRand(int s, int e){
    srand((unsigned) time(NULL));
    int ans=s+rand()%(e-s);
    return ans;
}
void suffleArr(array<int, 10> arr,int size){
    for(int i=size-1; i>=0; i--){
        int randIdx=getRand(0,i);
        swap(arr[i], arr[i]);
    }

    for(auto a:arr){
        cout<<a<<" ";
    }
}
int main()
{
    int size=10;
    array<int, 10> arr={1,5,3,4,8,2,5,6,9,10}; 
    cout<<getRand(0,size-1)<<endl;
    for(auto a:arr){
        cout<<a<<" ";
    }
    cout<<endl;
    suffleArr(arr, size);
    return 0;
}


try it, error in getting randIdx for swap
