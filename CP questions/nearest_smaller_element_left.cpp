#include<iostream>
#include<stack>
#include<vector>
#include<array>
using namespace std;
// min on left
int main(){
    array<int,6> arr={1,6,4,12,3,8};
    vector<int> output;
    stack<int> st;
    st.push(-1);
    for(const int num: arr){
        while(!st.empty() && st.top()>=num)
            st.pop();
        if(st.top()<num && !st.empty()){
            output.push_back(st.top());
        }
        st.push(num);
    }
    for(const int a:output){
        cout<<a<<" ";
    }
    return 0;
}