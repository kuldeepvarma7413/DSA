#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> &graph, vector<bool>& visited, int s, vector<bool> &path){
    visited[s]=true;
    path[s]=true;
    for(auto nbr: graph[s]){
        if(!visited[nbr]){
            bool cycleFound=isCycle(graph, visited, nbr, path);
            if(cycleFound){return true;}
        }else if(path[nbr]){
            return true;
        }
    }
    path[s]=false;
    return false;
}

int main(){
    vector<vector<int>> graph{{}, {2,4},
                                {3},
                                {4},
                                {5,1},
                                {} };
    vector<bool> visited(graph.size(), false);
    vector<bool> path(graph.size(), false);
    
    for(int i=0; i<graph.size(); i++){
        if(!visited[i] && isCycle(graph, visited, i, path)){
            cout<<"Cycle detected";
            return 0;
        }
    }
    cout<<"Cycle not found";
    return 0;
}

//done