#include<bits/stdc++.h>
using namespace std;
int dp[10001];
int noOfBST(int n){
    if(n==1 || n==0){return 1;}
    if(dp[n]!=-1){return dp[n];}
    int ans=0;
    for(int i=1; i<=n; i++){
        ans+=noOfBST(i-1)*noOfBST(n-i);
    }
    return dp[n]=ans;
}
int main(){
    memset(dp, -1, sizeof(dp));
    cout<<noOfBST(42);
    return 0;
}

// done using recursion with DP