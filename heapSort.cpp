// #include<bits/stdc++.h>
// using namespace std;
// // heap implementation
// class MaxHeap{
// private:
//     void Heapify(vector<int> &arr,int idx){
//         int l=idx*2, r=l+1;
//         if(idx==0){
//             l=1;
//             r=l+1;
//         }
//         int maxi=idx;
//         if(l< arr.size() && arr[idx]<arr[l]){maxi=l;}
//         if(r< arr.size() && arr[maxi]<arr[r]){maxi=r;}
//         if(maxi != idx){
//             swap(arr[idx], arr[maxi]);
//             Heapify(arr, maxi);
//         }
//     }
// public:
//     void push(vector<int> &arr, int data){
//         arr.push_back(data);
//         int idx=arr.size()-1;
//         while(idx>0 && arr[idx]>arr[idx/2]){
//             swap(arr[idx], arr[idx/2]);
//             idx/=2;
//         }
//     }
//     int pop(vector<int> &arr){
//         swap(arr[1], arr[arr.size()-1]);
//         arr.pop_back();
//         Heapify(arr, 0);
//     }
//     int top(vector<int> &arr){
//         return arr[0];
//     }
//     bool empty(vector<int> &arr){
//         return arr.size()==1;
//     }
//     void print(vector<int> &arr){
//         for(int i=0; i<arr.size(); i++){
//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//     }
//     MaxHeap(vector<int> &arr){
//         for(int i=0; i<arr.size(); i++){
//             Heapify(arr, arr[i]);
//         }
//     }
// };
// int main(){
//     vector<int> arr;
//     arr.reserve(15);
//     for(int i=10; i>1; i--){
//         arr.push_back(i*2);
//     }
//     for(auto a: arr){
//         cout<<a<<" ";
//     }
//     cout<<endl;
//     MaxHeap h1(arr);
//     h1.print(arr);
//     h1.pop(arr);
//     h1.print(arr);
//     return 0;
// }





#include<bits/stdc++.h>
using namespace std;

// how to heap sort in-place
//in place heap sort

void heapify(int arr[],int n,int i){
    int largest = i;
    int right = 2*largest+1;
    int left = right+1;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right  < n && arr[right] > arr[largest]){
        largest = right;
    }
     
   if(largest != i){
    swap(arr[largest],arr[i]);
    heapify(arr,n,largest);
   }
}


void heapSort(int arr[],int n){
    //constructing a maxHeap
  for(int i = n/2-1; i >= 0 ;i--){
    heapify(arr,n,i);
  }
  // to delete the last element with first element
  for(int i = n-1;i >= 0;i--){
    swap(arr[i],arr[0]);
    heapify(arr,i,0);
  }
}
int main(){

    int arr[5] = {4,5,1,3,7};

    heapSort(arr,5);

    for(int i = 0; i < 5;i++){
        cout<<arr[i]<<" ";
    }
}


heap sort