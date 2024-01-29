#include<bits/stdc++.h>
using namespace std;
vector<string> findSets(int idx, vector<int> &nums, vector<vector<int>> &ans){
    if(idx==1){
        return {"0","1"};
    }
    vector<string> ans=findSets(idx-1, nums, ans);

}
int main(){
    vector<int> nums={1,2,3,4};
    vector<vector<int>> ans;
    findSets(4, nums, ans);
    return 0;
}

do it yourself