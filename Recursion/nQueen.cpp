#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<string>> &board, int n, int i, int j){
    int row=i, col=j;
    while(row >= 0  && col >= 0){
        if(board[row--][col--] == "Q"){return false;}
    }

    row=i, col=j;
    while(row>=0){
        if(board[row--][col]=="Q"){return false;}
    }
    row=i, col=j;
    while(row >= 0 && col <= n-1){
        if(board[row--][col++]=="Q"){return false;}
    }
    return true;
}
void nQueen(vector<vector<string>> &board, int n, int i, vector<vector<string>>& output){
    if(i==n){
        vector<string> temp;
        for(auto b: board){
            string ans;
            for(auto a: b){
                ans+=a;
            }
            temp.push_back(ans);
        }
        output.push_back(temp);
        return;
    }

    for(int j=0; j<n; j++){
        if(isSafe(board, n, i, j)){
            board[i][j]="Q";
            nQueen(board, n, i+1, output);
            board[i][j]=".";
        }
    }
    return;
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> output;
    vector<vector<string>> board(n,vector<string>(n,"."));
    nQueen(board, n, 0, output);
    return output;
}

int main(){
    vector<vector<string>> ans=solveNQueens(6);
    for(auto a: ans){
        for(auto b: a){
            cout<<b<<endl;
        }
        cout<<endl;
    }
    return 0;
}

//done