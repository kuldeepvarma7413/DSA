#include<iostream>
using namespace std;

void swapAlternate(int arr[], int n){
    for(int i=0;i<n;i+=2){
        if(i+1<n){
            swap(arr[i],arr[i+1]);
        }
    }
}

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int even[8]={2,1,4,3,6,5,8,7};
    int odd[7]={2,1,4,3,6,5,7};

    swapAlternate(even,8);
    print(even,8);

    cout<<endl;

    swapAlternate(odd,7);
    print(odd,7);

    return 0;
} 