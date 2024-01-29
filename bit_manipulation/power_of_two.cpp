#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=6;
    if(!(n&(n-1))){
        cout<<"Power of 2.";   
    }else{
        cout<<"Not a power of 2.";
    }
    return 0;
}