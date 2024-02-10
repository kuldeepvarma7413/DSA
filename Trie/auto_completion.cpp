#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    unordered_map<char, Node*> children;
    bool isTerminal;
    Node(char d){
        data=d;
        isTerminal=false;
    }
};

class Trie{
    // create top most root node
    Node* root;
public:
    Trie(){
        root = new Node('\0');
    }

    void addWord(string word){
        // fetch root node
        Node* temp=root;
        for(const char c: word){
            if(temp->children.count(c)==0){
                temp->children[c]=new Node(c);
                temp=temp->children[c];
            }else{
                temp=temp->children[c];
            }
        }
        temp->isTerminal=true;
    }

    bool search(string word){
        // fetch root node
        Node* temp=root;
        for(const char c: word){
            if(temp->children.count(c)==0){
                return false;
            }else{
                temp=temp->children[c];
            }
        }
        return temp->isTerminal;
    }
};


int main(){
    string arr[]={"apple", "appy", "batman", "appie", "appstore"};
    Trie t;
    for(const string s:arr){
        t.addWord(s);
    }
    cout<<t.search("appie");
    return 0;
}

complete it