#include<bits/stdc++.h>
using namespace std;
vector<string> generate(int n, vector<string> &ans){
    // base case
    if(n==1){return {"()"};}
    // recursion
    vector<string> temp=generate(n-1, ans);
    for(auto t: temp){
        string tempans;
        tempans.append(t+t);
        // add in mid

        ans.push_back(tempans);
    }
    return ans;

}
int main(){
    int n=3;
    vector<string> ans;
    generate(n, ans);
    for(auto a: ans){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}


solve it

n==1    ()
n==2    ()()    (())
n==3    ()()()  ((()))  (()())  ()(())  (())()