#include<bits/stdc++.h>
using namespace std;

class Graph{
    // unweighted list
    int n;
    vector<int> *adjmtx;
public:
    Graph(int n){
        this->n=n;
        adjmtx=new vector<int>[n];
    }
    void addEdge(int u, int v, bool directed=true){
        if(directed){
            adjmtx[u].push_back(v);
        }else{
            adjmtx[u].push_back(v);
            adjmtx[v].push_back(u);
        }
    }
    void printAdjList(){
        for(int i=0; i<n; i++){
            cout<<i<<" : ";
            for(auto node: adjmtx[i]){
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2, false);
    g.addEdge(1,2);
    g.addEdge(2,3, false);
    g.addEdge(0,3);
    g.printAdjList();
    return 0;
}

// done