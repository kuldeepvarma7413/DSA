#include<bits/stdc++.h>
using namespace std;

void clearRangeOfBits(int &n, int i, int j){
    int mask1=(~0)<<j+1;
    int mask2=(1<<i)-1;
    int mask=mask1|mask2;
    n=mask&n;
}
void replaceBits(int &n, int i, int j, int m){
    // remove bits from i to j
    clearRangeOfBits(n,i,j);
    //shift m till ith bit
    m=m<<i;
    n=n|m;
}
int main()
{
    int n=15, i=1, j=3, m=2;
    cout<<n<<endl;   
    replaceBits(n,i,j,m);
    cout<<n<<endl;   
    return 0;
}