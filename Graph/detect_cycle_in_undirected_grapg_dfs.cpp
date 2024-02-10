#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> &graph, vector<bool>& visited, int s, int par){
    cout<<s<<" "<<par<<endl;
    visited[s]=true;
    for(auto nbr: graph[s]){
        cout<<"parent "<<par<<", start "<<s<<", nbr "<<nbr<<endl;
        if(!visited[nbr]){
            bool cycleFound=isCycle(graph, visited, nbr, s);
            if(cycleFound){return true;}
        }else if(nbr!=par){
            return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> graph{{}, {2,4},
                                {1,3},
                                {2,4},
                                {1,3,5},
                                {4} };
    vector<bool> visited(graph.size(), false);
    
    for(int i=0; i<graph.size(); i++){
        if(!visited[i] && isCycle(graph, visited, i, -1)){
            cout<<"Cycle detected";
            return 0;
        }
    }
    cout<<"Cycle not found";
    return 0;
}

//done