#include<bits/stdc++.h>
using namespace std;

bool isCycle(int s,vector<vector<int>> &graph){
    vector<bool> visited(graph.size());
    vector<int> par(graph.size());
    visited[s]=true;
    par[s]=-1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int f=q.front(); q.pop();
        for(auto nbr: graph[f]){
            if(!visited[nbr]){
                visited[nbr]=true;
                par[nbr]=f;
                q.push(nbr);
            }else if(par[f]!=nbr){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> graph{ {2,4},
                                {1,3},
                                {4,2},
                                {1,3,5},
                                {4} };
    

    if(isCycle(0, graph)){
        cout<<"Cycle found";
        return 0;
    }
    cout<<"No Cycle found";
    return 0;
}

// done