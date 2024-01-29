#include<iostream>
#include<array>
#include<vector>
using namespace std;
int main(){
    int count=0;     // {15,7,7,5,5,4,3,3}
    array <int,14> arr={15,-1,7,2,5,4,2,3};
    vector<int> maxCount(arr.size()-1);
    maxCount[arr.size()-1]=arr[arr.size()-1];
    for(int i=arr.size()-2; i>=0; i--){
        maxCount.push_back(max(maxCount[i+1], arr[i]));
    }
    for(int i=0; i<arr.size()-1;i++){
        if(arr[i]==maxCount[i])
            count++;
    }
    cout<<count;
    return 0;
}