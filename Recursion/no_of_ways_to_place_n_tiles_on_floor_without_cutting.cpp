#include<bits/stdc++.h>
using namespace std;
int noOfWays(int n){
    if(n==2){return 2;}
    if(n==1){return 1;}
    return noOfWays(n-1)+noOfWays(n-2);
}
int main(){
    int n=4, size=4; // tile size 1x4
    cout<<noOfWays(n);
    return 0;
}