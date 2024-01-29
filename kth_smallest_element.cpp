#include<bits/stdc++.h>
using namespace std;
int partation(array<int, 5> arr, int s, int e){
    int pivot=arr[e];
    int i=s-1;
    for(int j=s; j<e; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[e]);
    return i+1;
}
int quickSort(array<int,5> &arr, int s, int e, int k){
    // if(s>=e){
    //     return -1;
    // }
    int pivotIndex=partation(arr, s, e);
    if(pivotIndex==k-1){
        return arr[pivotIndex];
    }else if(pivotIndex > k-1){
        return quickSort(arr, s, pivotIndex-1,k);
    }else if (pivotIndex < k-1){
        return quickSort(arr, pivotIndex+1, e,k);
    }else{
        return -1;
    }
}
int main()
{
    array<int, 5> arr={5,8,1,15,4};
    cout<<quickSort(arr,0,4, 2)<<endl;
    // for(auto a: arr){
    //     cout<<a<<" ";
    // } 
    return 0;
}


using quick sort