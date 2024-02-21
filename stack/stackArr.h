#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

template<typename T>
class StackArr{
public:
    T arr[MAX];
    int topIdx=-1;
    void push(T d){
        if(topIdx>=1000){
            cout<<"Stack overflow";
            return;
        }
        arr[++topIdx]=d;
    }
    T pop(){
        if(topIdx<0){
            cout<<"Stack Underflow";
            return 0;
        }else{
            int x=arr[topIdx--];
            return x;
        }
    }
    T top(){
        if(topIdx>=0){
            return arr[topIdx];
        }
    }
    bool empty(){
        return topIdx<0;
    }
};