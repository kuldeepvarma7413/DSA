#include<iostream>
#include<array>
#include<limits.h>
using namespace std;
//all elements must not be negative
int main(){
    array<int, 6> nums={5,3,-2,-2,6,-4};
    int maxSum=INT_MIN;
    int csum=0;
    for(int i=0; i<nums.size(); i++){
        csum+=nums[i];
        maxSum=max(maxSum, csum);
        if(csum<0){csum=0;}
    }
    cout<<maxSum;
    return 0;
}
