#include<bits/stdc++.h>
using namespace std;
void incr(int n){
    if(n==0){return;}
    incr(n-1);
    cout<<n<<" ";
}
void desc(int n){
    if(n==0){return;}
    cout<<n<<" ";
    desc(n-1);
}
int main()
{
    incr(5);
    cout<<endl;
    desc(5);   
    return 0;
}