#include<bits/stdc++.h>
using namespace std;

struct MAT{
    int size;
    vector<vector<int>> matrix;

    // constructor
    MAT(int siz){
        size=siz;
        matrix.resize(size, vector<int>(size,0));
    }

    // make it identity matrix
    void identity(){
        for(int i=0; i<matrix.size(); i++){
            matrix[i][i]=1;
        }
    }

    // print matrix
    void print(){
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    // overload + operator (add two matrices)
    MAT operator +(MAT a){
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                a.matrix[i][j]+=matrix[i][j];
            }
        }
        return a;
    }

    // overload - operator (substract two matrices)
    MAT operator -(MAT a){
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                a.matrix[i][j]-=matrix[i][j];
            }
        }
        return a;
    }
    
    // overload * operator (multiply two matrices)
    MAT operator *(MAT a){
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                a.matrix[i][j]-=matrix[i][j];
            }
        }
        return a;
    }
};
int main()
{
    MAT matrix1(3), matrix2(3);
    matrix1.identity();
    matrix2.identity();
    matrix1.print();
    cout<<"\n";

    MAT matrix3=matrix1+matrix2;
    matrix3.print();
    cout<<"\n";
    
    MAT matrix4=matrix1-matrix2;
    matrix4.print();
    cout<<"\n";
    
    MAT matrix5=matrix1*matrix2;
    matrix5.print();
    cout<<"\n";
    return 0;
}
    // vector<vector<int>> mat(3, vector<int>(3));
    // for(int i=0; i<mat.size(); i++){
    //     for(int j=0; j<mat[0].size(); j++){
    //         mat[i][j]=(i+1)*(j+1);
    //     }
    // }
    // vector<vector<int>> mat2(3, vector<int>(3));
    // for(int i=0; i<mat.size(); i++){
    //     for(int j=0; j<mat[0].size(); j++){
    //         mat[i][j]=(i+2)*(j+2);
    //     }
    // }
    // //resultant matrix


    matrix exponention