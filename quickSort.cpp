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
void quickSort(array<int,5> &arr, int s, int e){
    if(s>=e){
        return;
    }
    int pivotIndex=partation(arr, s, e);
    quickSort(arr, s, pivotIndex-1);
    quickSort(arr, pivotIndex+1, e);
    return;
}
int main()
{
    array<int, 5> arr={5,2,4,3,1};
    quickSort(arr,0,4);  
    for(auto a: arr){
        cout<<a<<" ";
    } 
    return 0;
}