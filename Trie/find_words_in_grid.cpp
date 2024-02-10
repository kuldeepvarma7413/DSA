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
public:
    Node* root;
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

    pair<bool, Node*> search(char c, Node* temp){
        for(auto ch=temp->children.begin(); ch!=temp->children.end(); ch++){
            if(ch->first==c){
                temp=ch->second;
                return {true, temp};}
        }
        return {false, temp};
    }
};

vector<int> dx{-1,-1,-1,0,1,1,1,1};
vector<int> dy{-1,0,1,1,1,0,-1,-1};

void findWord(vector<vector<char>>& grid, Trie& t, int i, int j, vector<vector<string>>& ans, string history, Node* temp){
    // if we reach out of grid
    if((i<0 || j<0) || (i>grid.size() || j>grid[0].size())){return;}
    // search in Trie
    if(temp->isTerminal){
        cout<<history<<" ";
    }
    pair<bool, Node*> res=t.search(grid[i][j], temp);
    if( res.first){
        history+=grid[i][j];
        temp=res.second;
        for(int i=0; i<8; i++){
            findWord(grid, t, i, j, ans, history, temp);
        }
    }
    return;
}


int main(){
    string arr[]={"tea", "teabreak", "snack", "snacks", "songs", "swe"};
    Trie t;
    for(const string s:arr){
        t.addWord(s);
    }
    // grid
    vector<vector<char>> grid{
        {'s','s','n','t','s'},
        {'n','c','a','e','w'},
        {'e','r','b','k','e'},
        {'s','a','t','u','v'},
        {'x','y','k','w','x'},
    };

    vector<vector<string>> ans;
    Node* root=t.root;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            findWord(grid, t, i,j, ans, "", root);
        }
    }
    return 0;
}

complete it