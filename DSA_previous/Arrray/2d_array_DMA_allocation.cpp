#include <iostream>
using namespace std;

int main() {
    int row;
    int col;
    cin>>row>>col;
    // Write C++ code here
    int **a=new int*[row];
    for(int i=0;i<row;i++){
        a[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    //deleting columns
    for(int i=0;i<row;i++){
        delete a[i];
    }

    delete []a;

    return 0;
}