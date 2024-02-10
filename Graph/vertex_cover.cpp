#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;

vector<int> gr[N];
int memo[N][2];
int cnt=0;

int dp(int curr,int parent, int take){
    if(memo[curr][take]!=-1){return memo[curr][take];}
    cnt++;
    int ans=take;
    for(auto child: gr[curr]){
        if(child!=parent){
            if(take){
                ans+=min( dp(child, curr, 0), dp(child, curr, 1) );
            }else{
                ans+=dp(child, curr, 1);
            }
        }
    }
    return memo[curr][take]=ans;
}

int main(){
    int n;
    cin>>n;
    memset(memo, -1, sizeof(memo));
    for(int i=0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    cout<<min(dp(1,0,0), dp(1,0,1))<<endl;

    cout<<cnt<<endl;
    return 0;
}

look into it