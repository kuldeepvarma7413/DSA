#include<bits/stdc++.h>
using namespace std;

void updateIthBit(int &n, int i, int b){
    // clear ith bit
    int mask=~(1<<i);
    n=n&mask;
    // replace ith bit with given bit
    int mask2=b<<i;
    n=n|mask2;
}
int main()
{
    int n=16;
    cout<<n<<endl;
    updateIthBit(n, 3, 1);
    cout<<n<<endl;
    return 0;
}

// updateIthBit filename asks for admin permission to execute code