#include<bits/stdc++.h>
#include "hashmap_implementation.h"
using namespace std;
int main(){
    Hashtable<int> h;
    h.insert("Dosa", 100);
    h.insert("Chai", 20);
    h.insert("Maggi", 60);
    h.insert("Coffee", 40);
    h.insert("Paneer Dosa", 120);
    h.insert("Adrak Chai", 25);

    string item;
    cin>>item;

    int* val=h.search(item);
    if(val==NULL){
        cout<<"Item not found";
    }else{
        cout<<"Price of "<<item<<" is "<<(*val);
    }
    return 0;
}