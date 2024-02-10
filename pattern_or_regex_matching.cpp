#include<bits/stdc++.h>
using namespace std;
bool match(string &pattern, string &text, int i, int j){
    if(i<0 && j< 0){return true;}
    if(i<0 && j>=0){return false;}
    // if pattern has n ******
    if(i>=0 && j<0){
        for(int k=0; k<=i; k++){
            if(pattern[k]!='*'){return false;}
        }
        return true;
    }

    if(pattern[i]==text[j] || pattern[i]=='?'){
        return match(pattern, text, i-1, j-1);
    }else if(pattern[i]=='*'){
        return ( match(pattern, text, i-1, j) || match(pattern, text, i, j-1));
    }

    return false;
}
int main(){
    string pattern="aa";
    string text="aa";
    cout<<match(pattern, text, pattern.size()-1, text.size()-1);
    return 0;
}