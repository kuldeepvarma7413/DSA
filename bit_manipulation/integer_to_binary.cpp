#include<bits/stdc++.h>
using namespace std;
// using int cant store 32 bits number in int form;
// int convertToBinary(int n){
//     int power=1, ans=0;
//     while(n>0){
//         ans+= power * (n&1);
//         power*=10;
//         n=n>>1;
//     }
//     return ans;
// }
string convertToBinary(int n){
    string ans="";
    while(n>0){
        int rem=n%2;
        ans.append(to_string(rem));
        n=n/2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n=16;
    cout<<convertToBinary(n);   
    return 0;
}