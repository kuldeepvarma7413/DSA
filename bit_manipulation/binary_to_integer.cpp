#include<bits/stdc++.h>
using namespace std;
int convertToInt(int n){
    int power=1, ans=0;
    while(n>0){
        ans+=power*(n&1);
        power*=2;
        n=n/10;
    }
    return ans;
}

int main()
{
    cout<<convertToInt(101);
    return 0;
}