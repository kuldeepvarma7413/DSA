// Given are N boards of with length of each given in the form of array, and K painters, 
// such that each painter takes 1 unit of time to paint 1 unit of the board. The task is 
// to find the minimum time to paint all boards under the constraints that any painter will
// only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

#include<bits/stdc++.h>
using namespace std;

bool check(int time, vector<int> &boards, int k){
    int currtime=0, painters=1;
    for(auto board:boards){
        if(currtime+board>time){
            painters++;
            currtime=0;
        }
        currtime+=board;
    }
    return painters<=k;
}

int main(){
    int n, k;
    cin>>n>>k;
    int maxi=INT_MIN, sum=0;
    vector<int> boards(n);
    for(int i=0; i<n; i++){
        cin>>boards[i];
        sum+=boards[i];
        maxi=max(maxi, boards[i]);
    }
    // logic
    int s=maxi, e=sum, ans=0;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(check(mid, boards, k)){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    cout<<ans;
    return 0;
}