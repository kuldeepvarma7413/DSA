#include<bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n, char src, char help, char dest){
    if(n==0){return;}
    // call for shifting n-1 disks to helper
    towerOfHanoi(n-1, src, dest, help);
    cout<<"moving "<<n<<" from "<<src<<" to "<<dest<<endl;
    // call for shifting 1 disk to dest 
    towerOfHanoi(n-1, help, src, dest);
}
int main(){
    towerOfHanoi(4, 'A', 'B', 'C');
    return 0;
}

//done