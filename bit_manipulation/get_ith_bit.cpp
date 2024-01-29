#include<bits/stdc++.h>
using namespace std;
int getIthBit(int n, int i){
    int mask=(1<<i);
    return (mask&n)>0 ? 1 : 0;
}
int main()
{
    cout<<getIthBit(5,3);   
    return 0;
}