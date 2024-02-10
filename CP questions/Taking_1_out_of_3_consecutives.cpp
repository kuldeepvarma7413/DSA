#include<bits/stdc++.h>
using namespace std;

// top down
// int solve(vector<int>& arr, int i, vector<int>& dp){
//     if(i>=arr.size()){return 0;}
//     if(dp[i]!=-1){return dp[i];}

//     int a=solve(arr, i+1, dp)+arr[i];
//     int b=solve(arr, i+2, dp)+arr[i+1];
//     int c=solve(arr, i+3, dp)+arr[i+2];
//     return dp[i]=min(a, min(b,c));
// }

// bottom up
int solve(vector<int> &arr, vector<int> &dp){
    // window size 3 fixed
    for(int i=3; i<dp.size(); i++){
        dp[i]= arr[i]+min(dp[i-1], min(dp[i-2], dp[i-3]));
    }
    int a=dp[dp.size()-1];
    int b=dp[dp.size()-2];
    int c=dp[dp.size()-3];
    return min(a, min(b,c));
    
}
int main(){
    vector<int> arr{3,2,1,1,2,3,1,3,2,1};
    vector<int> dp(arr.size());
    dp[0]=arr[0];
    dp[1]=arr[1];
    dp[2]=arr[2];
    // vector<int> dp(arr.size(), -1);
    // cout<<solve(arr, 0, dp);
    cout<<solve(arr, dp);
    return 0;
}