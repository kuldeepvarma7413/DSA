#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    // unweighted list
    unordered_map<T, list<T>> adjList;
public:
    void addEdge(T u, T v, bool directed=true){
        if(directed){
            adjList[u].push_back(v);
        }else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto it: adjList){
            cout<<it.first<<" : ";
            for(auto node: it.second){
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph<string> g;
    g.addEdge("delhi", "mumbai");
    g.addEdge("mumbai", "kolkata", false);
    g.addEdge("kolkata", "bhopal", false);
    g.addEdge("bhopal", "amritsar");
    g.printAdjList();

    Graph<int> g1;
    g1.addEdge(0,1);
    g1.addEdge(0,2, false);
    g1.addEdge(1,2);
    g1.addEdge(2,3, false);
    g1.addEdge(0,3);
    g1.printAdjList();
    return 0;
}

//done