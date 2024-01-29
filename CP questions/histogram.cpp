#include<iostream>
#include<array>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;
int main(){
    array<int, 6> heights={2,1,5,6,2,3};
    vector<int> prevsmall;
    vector<int> nextsmall(heights.size());
    stack<int> st;
    int maxArea=INT_MIN;
    for(int i=0; i<heights.size(); i++){
        while(!st.empty() && heights[st.top()]>=heights[i]){ st.pop(); }
        prevsmall.push_back(st.empty()? -1 : st.top());
        st.push(i);
    }
    while(!st.empty()){st.pop();}
    for(int i=heights.size()-1; i>=0; i--){
        while(!st.empty() && heights[st.top()]>=heights[i]){ st.pop(); }
        nextsmall[i]=(st.empty()? heights.size() : st.top());
        st.push(i);
    }
    for(int i=0; i<heights.size(); i++){
        int area=heights[i]*(nextsmall[i]-prevsmall[i]-1);
        maxArea=max(maxArea, area);
    }
    return maxArea;
}