#include<bits/stdc++.h>
using namespace std;
int main()
{
    array<int, 8> arr={5, 7, 3, 2, 11, 3, 5, 2};
    int xorval=0;
    for(auto a: arr){
        xorval ^= a;
    }
    // got xor val of 2 unique elements
    int count=0;
    int temp=xorval;
    while(temp>0){
        if(temp&1){
            break;
        }
        count++;
        temp=temp>>1;
    }
    //got ith bit == 1 (count), now find in arr
    int firstval=0;
    for(auto a: arr){
        int val=a>>count;
        if(val&1){
            firstval= firstval^xorval^a;
        }
    }
    cout<<firstval<<" "<<(firstval^xorval);

    return 0;
}