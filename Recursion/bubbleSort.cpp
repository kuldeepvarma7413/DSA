#include<bits/stdc++.h>
using namespace std;
// recursion using for loop
// void bubbleSort(int num[], int n){
//     if(n==1)
//         return;
//     int count=0;
//     for(int i=0; i<n-1; i++){
//         if(num[i]>num[i+1]){
//             swap(num[i], num[i+1]);
//             count++;
//         }
//     }
//     if(count==0){return;}
//     bubbleSort(num, n-1);
// }
//recursion without using for loop
void bubbleSort(int num[], int n, int i){
    if(n==1){return;}
    if(i==n-1){
        bubbleSort(num, n-1, 0);
        return;
    }
    if(num[i]>num[i+1]){
        swap(num[i], num[i+1]);
    }
    bubbleSort(num, n, i+1);
}
int main(){
    int nums[]={5,8,6,4,2};
    // bubbleSort(nums, 5);     // using for loop
    bubbleSort(nums, 5, 0);     // without using for loop
    for(auto a:nums){cout<<a<<" ";}
    return 0;
}

//done