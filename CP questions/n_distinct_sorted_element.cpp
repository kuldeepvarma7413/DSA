// Q. pair sum -> n distinct elements, a[i]+a[j]=k

#include<iostream>
#include<array>
#include<unordered_set>
using namespace std;
//set O(N)
int main(){
    array<int, 10> arr={-3,0,1,3,6,8,11,14,18,25};
    unordered_set<int> myset;
    int k=5;
    for(int i=0; i<arr.size(); i++){
        if(myset.count(k+arr[i])){
            cout<<arr[i]+k<<" "<<arr[i]<<endl;
        }else if(myset.count(arr[i]-k)){
            cout<<arr[i]<<" "<<arr[i]+k<<endl;
        }
        myset.insert(arr[i]);
    }
    return 0;
}

//two pointer approach (sorted) 
// int main(){
//     array<int, 10> arr={-3,0,1,3,6,8,11,14,18,25};
//     int k=5;
//     int s=0, e=0;
//     while(s<=e && e<arr.size()){
//         if(arr[e]-arr[s]==k){
//             cout<<"index "<<s++<<" "<<e++<<" Value "<<arr[s]<<" "<<arr[e]<<endl;
//             // expression right to left
//         }else if(arr[e]-arr[s]<=k){
//             e++;
//         }else{
//             s++;
//         }
//     }
//     return 0;
// }