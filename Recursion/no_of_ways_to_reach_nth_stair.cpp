#include<bits/stdc++.h>
using namespace std;

// result vector by reference
int noOfSteps(int n, vector<int>& res){
    if(n==0){
        res.push_back(0);
        for(int i=0; i<res.size()-1; i++){
            cout<<abs(res[i]-res[i+1])<<" ";
        }
        cout<<endl;
        res.pop_back();
        return 1;
    }
    else if(n<0){ return 0;}
    res.push_back(n);
    int ans= noOfSteps(n-1, res)+noOfSteps(n-2, res)+noOfSteps(n-3, res);
    res.pop_back();
    return ans;
}
//without by reference
// int noOfSteps(int n, vector<int> res){
//     if(n==0){
//         res.push_back(0);
//         for(int i=0; i<res.size()-1; i++){
//             cout<<abs(res[i]-res[i+1])<<" ";
//         }
//         cout<<endl;
       
//         return 1;
//     }
//     else if(n<0){ return 0;}
//     res.push_back(n);
//     int ans= noOfSteps(n-1, res)+noOfSteps(n-2, res)+noOfSteps(n-3, res);
//     return ans;
// }
int main()
{
    int n=4;
    vector<int> res;
    cout<<noOfSteps(n, res);   
    return 0;
}