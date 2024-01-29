#include<bits/stdc++.h>
using namespace std;
int main()
{
    array<int, 3> arr={1, 2, 3};
    vector<vector<int>> sets;
    for(int i=0; i<=(1<<arr.size())-1 ; i++){
        vector<int> temp;
        int count=0;
        int val=i;
        while(val>0){
            if(val&1){
                temp.push_back(arr[count]);
            }
            count++;
            val=val>>1;
        }
        sets.push_back(temp);
    }   
    cout<<endl;
    for(auto a:sets){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}