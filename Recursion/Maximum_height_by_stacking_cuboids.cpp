#include<bits/stdc++.h>
using namespace std;
class Container{
public:
    int length;
    int bredth;
    int height;
    Container(int a, int b, int c){
        length=a;
        bredth=b;
        height=c;
    }
};
static bool compare(Container a, Container b){
    return (a.length * a.bredth) > (b.length*b.bredth);
}
int main(){
    vector<Container> cnts{Container(3,2,8),Container(1,1,1),Container(2,2,3),Container(4,5,7),Container(1,1,3)};

    sort(cnts.begin(), cnts.end(), compare);
    vector<int> dp(cnts.size(),0);
    dp[0]=cnts[0].height;
    for(int i=1; i<cnts.size(); i++){
        for(int j=0; j<i; j++){
            if(cnts[j].length > cnts[i].length && cnts[j].bredth > cnts[i].bredth){
                dp[i]=max(dp[i], dp[j]+cnts[j].height);
            }
        }
    }
    cout<<*max_element(dp.begin(), dp.end());
    return 0;
}

do it