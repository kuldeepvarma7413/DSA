#include<bits/stdc++.h>
using namespace std;
int setIthBit(int &n, int i){
    int mask=~(1<<i);
    n=n&mask;
}
int main()
{
    int a=5;
    cout<<a<<endl;   
    setIthBit(a,0);
    cout<<a;   
    return 0;
}