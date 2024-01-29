#include <iostream>
#include <vector>
using namespace std;


int getMaxMangoes(vector<vector<int>> field){
    // calculate sum
    vector<vector<int>> fieldsum;
    for(int i=0; i<field.size(); i++){
        for(int j=0; j<field.size(); j++){
            fieldsum.push_back((j>0 ? fieldsum[i, j-1] : 0 + i>0 ? fieldsum[i-1, j] : 0 ) - (i>0 && j>0) ? fieldsum[i-1, j-1] : 0 + field[i][j]);
        }
    }

    // find max ram can get
    int maxOfRam=0;
    for(int i=0; i<field.size()-1; i++){
        int minOfRam=0;
        for(int j=0; j<field.size()-1; j++){
            // make a cut i,j
            int q1=fieldsum[i,j];
            int q2=fieldsum[i, field.size()-1]-q1;
            int q3=fieldsum[field.size()-1, j]-q1;
            int q4=fieldsum[field.size()-1]-q1-q2-q3;
            minOfRam=min({q1,q2,q3,q4});
            maxOfRam=max(maxOfRam, minOfRam);
        }
    }
    return maxOfRam;
}


int main(){
    vector<vector<int>> field={{1,2,3,1},{2,6,4,8}, {1,3,2,7}, {2,0,1,5}};
    cout<<getMaxMangoes(field);
    return 0;
}


complete it