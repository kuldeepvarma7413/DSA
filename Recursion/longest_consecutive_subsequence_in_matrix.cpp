#include<bits/stdc++.h>
using namespace std;
int helper(vector<vector<int>>& board, int i, int j, int m, int n){
    if(i<0 || j<0 || i==m || j==n){return 0;}
    int val=board[i][j];
    if(i>=0 && j>=0 && i<m && j<n){
        if(board[i-1][j-1]==val+1){return 1+helper(board, --i,--j,m,n);}
        else if(board[i-1][j]==val+1){return 1+helper(board, --i,j,m,n);}
        else if(board[i-1][j+1]==val+1){return 1+helper(board, --i,++j,m,n);}
        else if(board[i][j+1]==val+1){return 1+helper(board, i,++j,m,n);}
        else if(board[i+1][j+1]==val+1){return 1+helper(board, ++i,++j,m,n);}
        else if(board[i+1][j]==val+1){return 1+helper(board, ++i,j,m,n);}
        else if(board[i+1][j-1]==val+1){return 1+helper(board, ++i,--j,m,n);}
        else if(board[i][j-1]==val+1){return 1+helper(board, i,--j,m,n);}
    }
    return 0;
}
int main(){
    vector<vector<int>> board{{3,2,0},{4,1,6},{8,11,2},{10,7,3},{9,12,4},{11,20,5}};
    int m=6, n=3;
    int maxi=INT_MIN;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int seqlen=helper(board,i,j,m,n);
            maxi=max(maxi, seqlen);
        }
    }
    cout<<maxi;
    return 0;
}





// using memoization (optimized approach)

// #include<bits/stdc++.h>
// using namespace std;

// bool isInsideGrid(int i, int j, int m, int n){
//     if(i>=0 && j>=0 && i<m && j<n){return true;}
//     return false;
// }

// int helper(vector<vector<int>>& board, int i, int j, int m, int n, vector<vector<int>>& dp){
//     if(dp[i][j]!=-1){return dp[i][j];}

//     int ans=0;
//     int dx[]={0,-1,-1,-1,0,-1,1,1};
//     int dy[]={1,1,0,-1,-1,1,0,1};

//     for(int k=0; k<8; k++){
//         int ni=i+dx[k];
//         int nj=j+dy[k];
//         if(isInsideGrid(ni, nj, m, n) && board[ni][nj]-board[i][j]==1){
//             int sublen=helper(board, ni, nj, m, n, dp);
//             ans=max(ans,sublen);
//         }
//     }

//     return dp[i][j]=ans+1;
// }
// int main(){
//     vector<vector<int>> board{{3,2,0},{4,1,6},{8,11,2},{10,7,3},{9,12,4},{11,20,5}};
//     vector<vector<int>> dp{{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
//     int m=6, n=3;
//     int maxi=INT_MIN;
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             int seqlen=helper(board,i,j,m,n,dp);
//             maxi=max(maxi, seqlen);
//         }
//     }
//     cout<<maxi;
//     return 0;
// }

// solved