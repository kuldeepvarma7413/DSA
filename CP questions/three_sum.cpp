#include<iostream>
#include<array>
#include<unordered_set>
using namespace std;
int main(){
    array<int, 7> arr={3,1,4,6,2,2,7};
    int i=0, target=7;
    while(i<arr.size()-2){
        unordered_set<int> myset;
        int target1=target-arr[i];
        for(int j=i; j<arr.size(); j++){
            if(myset.count(target1-arr[j]) && (target1-arr[j] != arr[i])){
                cout<<arr[i]<<" "<<arr[j]<<" "<<target1-arr[j]<<endl;
            }
            myset.insert(arr[j]);
        }
        i++;
    }
}