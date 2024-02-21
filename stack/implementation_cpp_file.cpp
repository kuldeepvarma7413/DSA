#include<bits/stdc++.h>
#include "stackLL.h"
#include "stackV.h"
#include "stackArr.h"

using namespace std;
int main(){
    // using linked list
    Stack<char> s;
    // insert p e e d l u k
    s.push('p');
    s.push('e');
    s.push('e');
    s.push('d');
    s.push('l');
    s.push('u');
    s.push('k');

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl<<"Stack printed (Linked List)"<<endl;

    // using vector
    StackV<int> s1;
    // insert 6 5 4 3 2 1
    s1.push(6);
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);

    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl<<"Stack printed (Vector)"<<endl;

    // using array
    StackArr<char> s2;
    // insert a m r a v
    s2.push('a');
    s2.push('m');
    s2.push('r');
    s2.push('a');
    s2.push('v');

    while(!s2.empty()){
        cout<<s2.top()<<" ";
        s2.pop();
    }
    cout<<endl<<"Stack printed (Array)"<<endl;


    return 0;
}