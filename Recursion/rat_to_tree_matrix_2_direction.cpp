// // rat in maze in two direction (right and down)

#include<bits/stdc++.h>
using namespace std;

int ratInMaze(vector<vector<int>>& field, int i, int j, int n, vector<vector<int>>& dp){
    if(i==n-1 && j==n-1){return 1;}
    if(i==n || j==n){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}
    int ans=0;
    if(field[i][j]!=1){
        ans+=ratInMaze(field, i, j+1, n, dp);
    }
    if(field[i][j]!=1){
        ans+=ratInMaze(field, i+1, j, n, dp);
    }
    return dp[i][j]=ans;
}
int main(){
    vector<vector<int>> field{{0,0,0},
                              {0,0,0},
                              {0,1,0}};
    vector<vector<int>> dp(3, vector<int>(3,-1));
    cout<<ratInMaze(field, 0 ,0, 3, dp);
    return 0;
}

// done