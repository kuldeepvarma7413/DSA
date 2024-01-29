#include<bits/stdc++.h>
using namespace std;

bool check(int time,int orders,vector<int> &ranks, int n){
    // logic to find whether given cooks can cook no. of orders in given time
    int total=0;
    for(int rank:ranks){
        int cnt=0, ctime=0;
        while(ctime+(cnt+1)*rank <=time){
            cnt++;
            ctime+=cnt*rank;
        }
        total+=cnt;
    }
    return total>orders;
}
int main()
{
    int t=0;
    cin>>t;
    while(t--){
        int orders, cooks;
        cin>>orders>>cooks;
        vector<int> ranks(cooks);
        for(int i=0; i<cooks; i++){int a; cin>>a; ranks[i]=a;}
        sort(ranks.begin(), ranks.end());
        int ans=0;
        int timelower=0, timeupper=0;
        timeupper=ranks[0]*((orders*(orders-1))/2);
        // binary search in timebound
        while(timelower<=timeupper){
            int timemid=timelower+(timeupper-timelower)/2;
            if(check(timemid, orders, ranks, cooks)){
                ans=timemid;
                timeupper=timemid-1;
            }else{
                timelower=timemid+1;
            }
        }
        cout<<ans;
        return 0;
    }
}

// do it at your own