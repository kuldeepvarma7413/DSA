#include<bits/stdc++.h>
using namespace std;
// void print(vector<int> &arr){
//     for(auto a: arr){cout<<a<<" ";}
//     cout<<endl;
// }
int main(){
    vector<int> arr{3,2,4,1,7,8,6,10,9};
    vector<int> dp(arr.size(),1);
    int maxi=INT_MIN;
    for(int i=1; i<arr.size(); i++){
        int prev=arr[0];
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i], dp[j]+1);
            }
          
        }
        // print(dp);
    }
    cout<<*max_element(dp.begin(), dp.end());
    return 0;
}

// leetcode 300 completed