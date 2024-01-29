//find intersection if exist then return intersection (common elements of both arrays) otherwise return -1
#include<iostream>
#include<vector>
using namespace std;
/*
void findArrayIntersection(int arr[],int n,int arr1[],int m)
{
    for(int i=0;i<n;i++){
        int ans=arr[i];
        for(int j=0;j<m;j++){
            if(ans==arr1[j]){
                cout<<arr1[j]<<ends;
                arr1[j]=-1;
                break;
            }
        }
    }
}*/

vector<int> findArrayIntersection(vector<int> &arr,int n,vector<int> &arr1,int m)
{
    int i=0,j=0;
    vector<int> ans;
    while(i<n && j<m){
        if(arr[i]==arr1[j]){
            ans.push_back(arr[i]);
            i++;
            j++;
        }
        else if(arr[i]<arr1[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr={1,5,6,9,8};
    vector<int> arr1={4,9,5,6,2,5};
    int n=5,m=6;
    findArrayIntersection(arr,n,arr1,m);

    return 0;
}

//need some improvement and it takes more than 1 sec in executing