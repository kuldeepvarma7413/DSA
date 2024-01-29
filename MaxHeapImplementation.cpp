
#include<bits/stdc++.h>
using namespace std;
// heap implementation
class MaxHeap{
private:
    vector<int> arr;
    void Heapify(int idx){
        int l=idx*2, r=l+1;
        int maxi=idx;
        if(l< arr.size() && arr[idx]<arr[l]){maxi=l;}
        if(r< arr.size() && arr[maxi]<arr[r]){maxi=r;}
        if(maxi != idx){
            swap(arr[idx], arr[maxi]);
            Heapify(maxi);
        }
    }
public:
    MaxHeap(int n){
        arr.reserve(n);
        arr.push_back(-1);
    }
    void push(int data){
        arr.push_back(data);
        int idx=arr.size()-1;
        while(idx>1 && arr[idx]>arr[idx/2]){
            swap(arr[idx], arr[idx/2]);
            idx/=2;
        }
    }
    int pop(){
        swap(arr[1], arr[arr.size()-1]);
        arr.pop_back();
        Heapify(1);
    }
    int top(){
        return arr[1];
    }
    bool empty(){
        return arr.size()==1;
    }
    void print(){
        for(int i=1; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    MaxHeap h1(5);
    h1.push(3);
    h1.push(12);
    h1.push(7);
    h1.push(10);
    h1.push(5);
    h1.push(8);
    h1.push(2);
    h1.push(4);
    h1.print();
    h1.pop();
    h1.print();
    return 0;
}