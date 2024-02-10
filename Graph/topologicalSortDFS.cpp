#include<bits/stdc++.h>
using namespace std;

void DFSTopologicalHelper(vector<vector<int>>& adjList, int s, vector<bool>& visited, vector<int>& ans){
    visited[s]=true;
    for(auto node: adjList[s]){
        if(!visited[node]){
            DFSTopologicalHelper(adjList, node, visited, ans);
        }
    }
    ans.push_back(s);
    return;
}

int main(){
    // adj list
    vector<vector<int>> adjList{{1,2},{3},{3,4},{4},{5},{},{5}};
    vector<int> ans;
    vector<bool> visited(adjList.size(),0);
    for(int i=0; i<adjList.size(); i++){
        if(!visited[i]){
            DFSTopologicalHelper(adjList, i, visited, ans);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto a: ans){
        cout<<a<<" ";
    }
    return 0;
}