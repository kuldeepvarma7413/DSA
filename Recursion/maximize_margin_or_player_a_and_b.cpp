#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int s, int e, vector<vector<int>>& dp){
    if(s>e){return 0;}
    if(dp[s][e]!=-1){return dp[s][e];}
    int pickStart= arr[s] + min( solve(arr, s+2, e, dp), solve(arr, s+1, e-1, dp) );
    int pickEnd= arr[e] + min( solve(arr, s+1, e-1 , dp), solve(arr, s, e-2, dp) );
    return dp[s][e]=max( pickStart, pickEnd );
}

int main(){
    vector<int> arr{3,16,1,4,32,28,7,6};
    vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
    int sum=0;
    for(const int a: arr){sum+=a;}
    int forA=solve(arr, 0, arr.size()-1, dp) ;
    int forB=sum-forA;
    cout<<abs(forA-forB);
    return 0;
}

// done