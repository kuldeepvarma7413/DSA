#include<iostream>
#include<array>
using namespace std;
int main(){
    array<int, 11> arr={1,3,2,1,4,1,3,2,1,1,2};
    int s=0, e=0, k=8, currsum=arr[s], maxlength=arr.size(), maxLenStartIdx=-1, maxLenEndIdx=-1;
    while(e<arr.size()){
        if(currsum==k){
            if(maxlength>e-s+1){
                maxlength=e-s+1;
                maxLenStartIdx=s;
                maxLenEndIdx=e;
            }
        }
        if(currsum<k){
            e++;
            currsum+=arr[e];
        }
        else if(currsum>=k){
            currsum-=arr[s];
            s++;
        }
    }
    cout<<"Maxlength: "<<maxlength<<" "<<maxLenStartIdx<<" "<<maxLenEndIdx<<endl;
    return 0;
}