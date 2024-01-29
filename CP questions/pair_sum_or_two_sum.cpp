// Q. pair sum -> n distinct elements, a[i]+a[j]=k

#include<iostream>
#include<array>
#include<unordered_set>
using namespace std;
//set O(N)
// int main(){
//     array<int, 8> arr={5,1,3,8,7,2,6,9};
//     unordered_set<int> myset;
//     int k=14;
//     for(int i=0; i<arr.size(); i++){
//         if(myset.count(k-arr[i])){
//             cout<<arr[i]<<" "<<k-arr[i]<<endl;
//         }
//         myset.insert(arr[i]);
//     }
//     return 0;
// }

//two pointer approach (sorted) 
int main(){
    array<int, 8> arr={5,1,3,8,7,2,6,9};
    int k=14;
    int s=0, e=arr.size()-1;
    while(s<=e){
        if(arr[s]+arr[e]==k){
            cout<<"index "<<s--<<" "<<e--<<" Value "<<arr[s]<<" "<<arr[e]<<endl;
            // expression right to left
        }else{
            s++;
        }
    }
    return 0;
}