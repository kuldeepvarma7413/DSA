#include<bits/stdc++.h>
using namespace std;
int main(){
    // adj list
    vector<vector<int>> adjList{{1,2},{3},{3,4},{4},{5},{},{5}};
    vector<int> indeg(adjList.size());
    queue<int> q;
    for(auto adj: adjList){
        for(auto node: adj){
            indeg[node]++;
        }
    }
    for(int i=0; i<indeg.size(); i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int node=q.front();
        for(auto nd: adjList[node]){
            indeg[nd]--;
            if(indeg[nd]==0){
                q.push(nd);
            }
        }
        ans.push_back(node);
        q.pop();
    }
    for(auto a: ans){
        cout<<a<<" ";
    }
    return 0;
}