// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

///////////////////// Exponential ///////////////////////
/////////////////////////////////////////////////////////
int findpower(int a, int n){
    int ans=1;
    while(n>0){
        if(n&1)
            ans*=a;
        n>>=1;
        a*=a;
    }
    return ans;
}
// time complexity = O(logN)
// space complexity = O(1)

///////////////////// Recursive /////////////////////////
/////////////////////////////////////////////////////////
int findpower(int a, int n){
    if(n==0)
        return 1;
    int temp=findpower(a,n/2);
    temp*=temp;
    if(n%2==0)
        return temp;
    else
        return temp*a;
}
// time complexity = O(logN)
// space complexity = O(logN)

/////////////////////////////////////////////////////////
int findpower(int a, int n){
    if(n==0){
        return 1;
    }
    return n%2==0 ? findpower(a,n/2)*findpower(a,n/2) : findpower(a,n/2)*findpower(a,n/2)*a;
}
// time complexity = O(N)
// space complexity = O(logN)

/////////////////////////////////////////////////////////
int findpower(int a, int n){
    if(n==0){
        return 1;
    }
    return a*findpower(a,n-1);
}
// time complexity = O(N)
// space complexity = O(N)

///////////////////// Constant //////////////////////////
/////////////////////////////////////////////////////////
int findpower(int a, int n){
    int ans=1;
    for(int i=0; i<n; i++){
        ans*=a;
    }
    return ans;
}
// time complexity = O(N)
// space complexity = O(1)

/////////////////////////////////////////////////////////
int findpower(int a, int n){
    int ans=1;
    while(n>0){
        ans*=a;
        n--;
    }
    return ans;
}
// time complexity = O(N)
// space complexity = O(1)


int main() {
    cout<<findpower(2,3);
    return 0;
}
