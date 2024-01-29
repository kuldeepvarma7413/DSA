#include<iostream>
#include<array>
using namespace std;
// leetcode - container with most water
// gfg - container with most water
int main(){
    array<int, 7> height={3,1,5,8,6,2,7};
    int s=0, e=height.size()-1, maxcapacity=0;
    while(s<e){
        int capacity=(e-s)*min(height[s], height[e]);
        if(capacity>maxcapacity){
            maxcapacity=capacity;
        }
        if(height[s]<height[e]){
            s++;
        }else{
            e--;
        }
    }
    cout<<maxcapacity;
    return 0;
}
