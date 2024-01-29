#include<bits/stdc++.h>
using namespace std;
int noOfWays(int n){
    if(n==2){return 2;}
    if(n==1){return 1;}
    int ans=noOfWays(n-1)+(n-1) * noOfWays(n-2);
    return ans;
}
int main(){
    int n=3;
    cout<<noOfWays(n);
    return 0;
}