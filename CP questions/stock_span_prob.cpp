#include<iostream>
#include<stack>
#include<vector>
#include<array>
using namespace std;
// min on left
int main(){
    array<int,7> arr={100, 80, 120, 70, 60, 75, 85};
    stack<int> st;
    vector<int> ans;
    for(int i=0; i<arr.size(); i++){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans.push_back(i+1);
        }else{
            ans.push_back(i-st.top());
        }
        st.push(i);
    }
    for(const int a:ans){
        cout<< a<<" ";
    }
    return 0;
}