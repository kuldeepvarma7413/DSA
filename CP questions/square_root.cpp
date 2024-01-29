#include<iostream>
using namespace std;

float squareroot(int n){
    int intans;
    int s=0, e=n;
    while(s<=e){
        int mid=e-(s+e)/2;
        if(mid*mid > n){
            e=mid-1;
        }else if(mid*mid <= n){
            intans=mid;
            s=mid+1;
        }
    }
    float ans=float(intans);
    float inc=0.1;
    for(int i=0; i<3; i++){
        while(ans*ans <= n){
            ans+=inc;
        }
        ans-=inc;
        inc/=10;
    }
    return ans;
}

int main(){
    cout<<squareroot(1000);
    return 0;
}