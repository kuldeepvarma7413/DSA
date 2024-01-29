#include<bits/stdc++.h>
using namespace std;
void clearIBits(int &n, int i){
    int mask=(-1<<i);  // ~0 => -1 is similar to converting 00000 to 11111
    n=n&mask;
}
int main()
{
    int n=15;
    cout<<n<<endl;
    clearIBits(n, 2);
    cout<<n;   
    return 0;
}