#include<bits/stdc++.h>
using namespace std;
bool check(int mid, int cows, vector<long long int> stalls){
    // check if we can adjust cows in mid size
    //first cow at starting
    cows--;
    int j=0;
    for(int i=1; i<stalls.size(); i++){
        if(cows==0){return true;}
        else{
            if((stalls[i]-stalls[j])>=mid){
                j=i;
                cows--;
            }
        }
    }
    return cows==0;
}
int main()
{
    int t=0;
    cin>>t;
    while(t--){
        //  no of stalls and no of cows
        int n=0, c=0;
        cin>>n>>c;
        // positions of stalls
        vector<long long int> stalls(n);
        long long int mini=INT_MAX, maxi=INT_MIN;
        for(int i=0; i<n; i++){
            cin>>stalls[i];
            if(stalls[i]<mini){mini=stalls[i];}
            if(stalls[i]>maxi){maxi=stalls[i];}
        }
        // code to solve the problem
        sort(stalls.begin(), stalls.end());
        long long int s=0, e=maxi-mini, minDist=0;
        while(s<=e){
            long long int mid=s+(e-s)/2;
            if(check(mid, c,stalls)){
                minDist=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        cout<<minDist;
        return 0;
    }   
    return 0;
}
