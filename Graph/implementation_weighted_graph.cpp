#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    int n;
    // unweighted list
    unordered_map<T, list<pair<T,int>>> adjList;
public:
    Graph(int n){
        this->n=n;
    }
    void addEdge(T u, T v, int weight, bool directed=true){
        if(directed){
            adjList[u].push_back({v, weight});
        }else{
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u,weight});
        }
    }
    void printAdjList(){
        for(auto it: adjList){
            cout<<it.first<<" : ";
            auto neibours=it.second;
            for(auto node: neibours){
                cout<<"("<<node.first<<" "<<node.second<<"),";
            }
            cout<<endl;
        }
    }

    void bfs(){

    }

    int bfsSSSP(int s){
        //
        vector<bool> visited(n, false);
        vector<int> dist(n, INT_MAX) ;
        queue<int> q;
        q.push(s) ;
        visited[s]= true;
        dist[s]= 0;

        while(!q.empty()){
            int f = q.front();
            cout<<f<<" ";
            q.pop();
            for(auto nbr:adjList[f]){
                if(!visited[nbr]){
                    dist[nbr]=dist[f]+1;
                    visited[nbr]= true;
                    q.push(nbr);
                }
            }
        }
        //dist vector
        for(int i=0; i<dist.size(); i++){
            cout<<"Node "<<i<<" dist "<<dist[i]<<endl;
        }
    }
};
int main(){
    Graph<string> g(4);
    g.addEdge("A", "B",5, false);
    g.addEdge("A", "C",5, false);
    g.addEdge("C", "A",5, false);
    g.addEdge("E", "C",5, false);
    g.addEdge("A", "E",5, false);
    g.addEdge("E", "C",5, false);
    g.printAdjList();
    g.bfsSSSP(0);

    return 0;
}

rectify