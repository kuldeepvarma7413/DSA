#include<iostream>
#include<vector>
#include<array>
using namespace std;
int main(){
    array <int,14> arr={1,4,6,5,1,5,2,6,4,4,2,1,5};
    int A=-1, B=-1, minSubArraySize=13, mini=1, maxi=6;  // a contains max index, b contains min index
    if(mini== -1 || maxi == -1){
        cout<<"Both elements are not present";
        return 0;
    }
    for(int i=arr.size()-1; i>=0; i--){
        if(arr[i]==maxi){
            A=i;
        }else if(arr[i]==mini){
            B=i;
        }
        if(A!= -1 && B!= -1)
            minSubArraySize=min(minSubArraySize,abs(A-B)+1);
    }
    cout<<minSubArraySize;
    return 0;
}