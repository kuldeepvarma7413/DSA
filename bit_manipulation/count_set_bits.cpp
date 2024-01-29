#include<bits/stdc++.h>
using namespace std;
// void countSetBits(int n){
//     int onecount=0, zerocount=0;
//     while(n>0){
//         if((n&1)==1){onecount++;}
//         else{zerocount++;}
//         n=n>>1;
//     }
//     cout<<zerocount<<" Bits are 0 and "<<onecount<<" Bits are 1.";
// }

// optimized
void countSetBits(int n){
    int count=0;
    // iterations = no. of 1 bits
    while(n>0){
        n=n & (n-1);
        count++;
    }
    cout<<count<<" no. of 1 bits";
}
int main()
{
    int n=15;
    countSetBits(n);   
    return 0;
}