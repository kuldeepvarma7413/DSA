// Online C++ compiler to run C++ program online
#include <iostream>
#include <set>
using namespace std;

int main(){
    multiset<int> myset;
    multiset<int>::iterator itlow, itup;
    for(int i=0; i<6; i++) myset.insert(i*10);
    myset.insert(20);
    myset.insert(30);

    itlow=myset.lower_bound(32);
    cout<<*itlow<<endl;
    itup=myset.upper_bound(32);
    cout<<*itup<<endl;
    // myset.erase(itlow);
    // for(multiset<int>::iterator it=myset.begin(); it!=myset.end(); it++){
    //     cout<<*it<<" ";
    // }
    return 0;
}