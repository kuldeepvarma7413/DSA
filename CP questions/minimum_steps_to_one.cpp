#include<bits/stdc++.h>
using namespace std;
int minmSteps(int num){
    if(num==1){
        return 0;
    }
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    if(num%3==0){
        a=1+minmSteps(num/3);
    }
    if(num%2==0){
        b=1+minmSteps(num/2);
    }else{
        c=1+minmSteps(num-1);    
    }
    return min(a,min(b,c));
}
int main()
{
    int number=31;
    cout<<minmSteps(number);
    return 0;
}