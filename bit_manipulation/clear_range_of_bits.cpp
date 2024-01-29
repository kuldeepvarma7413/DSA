#include<bits/stdc++.h>
using namespace std;
void clearRangeOfBits(int &n, int i, int j){
    int mask1=(~0)<<j+1;
    int mask2=(1<<i)-1;
    int mask=mask1|mask2;
    n=n&mask;
}
int main()
{
    int n=31;
    cout<<n<<endl;   
    clearRangeOfBits(n,1,3);    // (number, ith position, jth position)
    cout<<n<<endl;   
    return 0;
}