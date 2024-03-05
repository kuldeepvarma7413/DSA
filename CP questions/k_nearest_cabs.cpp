#include<bits/stdc++.h>
using namespace std;
int main(){
    int k=3;
    vector<vector<int>> distances(4);
    for(int i=0; i<4; i++){
        vector<int> temp;
        temp.push_back((i+1)*1);
        temp.push_back((i+1)*2);
        distances[i]=temp;
    }
    vector<int> dist;
    for(int i=0; i < distances.size(); i++){
        dist.push_back( abs(distances[i][0]) + abs(distances[i][1]) );
    }
    priority_queue<int, vector<int>, greater<int>> totaldistance;
    int i=0;
    while(i<dist.size()){
        if(totaldistance.size()<k){totaldistance.push(dist[i]);}
        if(totaldistance.size()==k){
            if(totaldistance.top()>dist[i]){
                totaldistance.pop();
                totaldistance.push(dist[i]);
            }
        }
        i++;
    }
    while(k>0 && totaldistance.size()>0){
        cout<<totaldistance.top()<<" "; totaldistance.pop();
    }
    return 0;
}

// solved