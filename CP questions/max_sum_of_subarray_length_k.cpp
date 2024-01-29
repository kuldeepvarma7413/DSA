#include<iostream>
#include<array>
#include<unordered_set>
using namespace std;
int main(){
    array<int, 7> arr={-3,2,5,1,6,8,-5};
    int k=4;
    int s=0, e=k-1;
    int maxSum=0, currStartIndex=-1, currEndIndex=-1;
    while(e<arr.size()){
        int tempsum=0;
        for(int i=s; i<=e; i++){
            tempsum+=arr[i];
        }
        if(tempsum>maxSum){
            maxSum=tempsum;
            currStartIndex=s;
            currEndIndex=e;
        }
        s++;
        e++;
    }
    cout<<"Window indexes "<<currStartIndex<<" "<<currEndIndex<<" ans sum "<<maxSum;
    return 0;
}