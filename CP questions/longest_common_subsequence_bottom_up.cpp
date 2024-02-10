#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1="abcd", s2="axbgc";
    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1,0));
    int l=s1.length(), m=s2.length();
    for(int i=1; i<dp.size(); i++){
        for(int j=1; j<dp[0].size(); j++){
            if(s1[i]==s2[j]){
                dp[i][j]=1+max(dp[i-1][j], dp[i][j-1]);
            }else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // print sequence
    do it
    cout<<dp[l][m];
    return 0;
}

// bottom up dp