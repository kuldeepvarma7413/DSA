#include<bits/stdc++.h>
using namespace std;
bool compareit(int a, int b){
    string A=to_string(a);
    string B=to_string(b);
    return (A+B) > (B+A) ? 1 : 0;
}
int main()
{
    array<int, 5> arr={20,54,65,2,35};
    sort(arr.begin(), arr.end(), compareit);
    string ans="";
    for(auto a:arr){
        ans+=to_string(a);
    }   
    cout<<ans;
    return 0;
}