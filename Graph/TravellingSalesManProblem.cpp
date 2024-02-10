#include<bits/stdc++.h>
using namespace std;


int travellingSalesMan(int dist[][10], int n, int city, int visited, vector<vector<int>>& dp){
    // if visited return
    if(visited==(1<<n)-1){
        return dist[city][0];
    }

    if(dp[city][visited]!=-1){return dp[city][visited];}

    int ans=INT_MAX;
    // go for all cities
    for(int nbr=0; nbr<n; nbr++){
        if( (visited & (1<<nbr)) == 0 ){
            int cost=dist[city][nbr]+travellingSalesMan(dist, n, nbr, visited | (1<<nbr), dp);
            ans=min(cost, ans);
        }
    }
    return dp[city][visited]=ans;
}

int main(){
	int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
	};
    vector<vector<int>> dp(10,vector<int>(pow(2,10),-1));   // 2^n bcoz we are taking visited in binary

	int n = 4;
    cout<<travellingSalesMan(dist, n, 0, 1, dp);

	return 0;
}

// done