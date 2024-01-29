#include<bits/stdc++.h>
using namespace std;
int getIthBit(int n, int i){
    int mask=(1<<i);
    n=n&mask;
    return n>0 ? 1 : 0;
}
int setIthBit(int n, int i){
    int mask=(1<<i);
    n=n|mask;
    return n;
}
int clearIthBit(int n , int i){
    int mask=~(1<<i);
    n=n&mask;
    return n;
}
int updateIthBit(int n, int i, int b){
    n=clearIthBit(n,i);
    int mask=b<<i;
    return n|mask;
}
int countSetBits(int n){
    int count=0;
    while(n>0){
        if(n&1){
            count++;
        }
        n=n>>1;
    }
    return count;
}
int clearRangeOfBits(int n, int i, int j){
    int mask1=(~0)<<j+1;
    int mask2=~((~0)<<i);
    int mask=mask1+mask2;
    return n&mask;
}
int main()
{
    int n=16;
    cout<<getIthBit(n, 2)<<endl;
    cout<<setIthBit(n, 2)<<endl;
    cout<<clearIthBit(n, 2)<<endl;
    cout<<updateIthBit(n, 1, 1)<<endl;
    cout<<countSetBits(n)<<endl;
    cout<<clearRangeOfBits(n, 1, 2)<<endl;
    return 0;
}