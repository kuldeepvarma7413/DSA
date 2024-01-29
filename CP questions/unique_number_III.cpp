#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k=3;
    array<int, 7> arr={7,99,7,5,2,2,2};
    vector<int> bitcount(32);
    for(int i=0; i<arr.size();i ++){
        int val=arr[i], count=0;
        while(val>0){
            if(val&1){
                bitcount[count]++;
            }
            count++;
            val=val>>1;
        }
    }   
    for(int i=0; i<bitcount.size(); i++){
        bitcount[i]=bitcount[i]%k;
    }
    int power=1;
    int num=0;
    for(auto a:bitcount){
        num+=power*a;
        power*=2;
    }
    cout<<num;
    return 0;
}