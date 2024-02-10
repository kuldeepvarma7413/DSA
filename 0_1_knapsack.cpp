#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& dp){
    for(auto d: dp){
        for( auto a: d){
            cout<<a<<" ";
        }
        cout<<endl;
    }
}


int knapsack(vector<int>& weights, vector<int>& prices, int n, int c, vector<vector<int>>& dp){
    // base case
    if(c<=0 || n==0){return 0;}
    // DP
    if(dp[n][c]!=-1){return dp[n][c];}
    int picked=0, notpicked=0;
    // include
    if(c-weights[n-1]>=0){
        picked=prices[n-1]+knapsack(weights, prices, n-1, c-weights[n-1], dp);
    }
    // exclude
    notpicked=knapsack(weights, prices, n-1, c, dp);
    
    return dp[n][c]=max(picked, notpicked);
}

int main(){
    int c=10;   // capacity
    vector<int> weights{2,5,3,7};
    vector<int> prices{20,30,15,40};
    int n=weights.size();
    vector<vector<int>> dp(n+1, vector<int>(c+1,-1));
    cout<<knapsack(weights, prices, n, c, dp);
    return 0;
}

// if we can pick infinite then we don't need to reduce n
// gfg  1 knapsack

//done