#include<iostream>
#include<array>
using namespace std;

int main(){
    array <int,14> arr={'a','b','g', 'a','g', 'c','b','g', 'a','g'};
    int ans=0, gcount=0;
    for(int i=arr.size()-1; i>=0; i--){
        if(arr[i]=='g')
            gcount++;
        if(arr[i]=='a')
            ans+=gcount;
    }
    cout<<ans;
    return 0;
}
