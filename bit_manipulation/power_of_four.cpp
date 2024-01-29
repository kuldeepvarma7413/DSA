#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=16, count=0;
    while((n&1)==0){
        count++;
        n=n>>1;
    }
    n=n>>1;
    if((count&1)==0 && count>0 && n==0){
        cout<<"Power of 4.";
    }else{
        cout<<"Not a Power of 4.";
    }
    return 0;
}