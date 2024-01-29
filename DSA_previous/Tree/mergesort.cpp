#include<iostream>
using namespace std;

void merge(int A[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int *L=new int(n1);
    int *R=new int(n2);
    for(int i=0;i<n1;i++){
        L[i]=A[p+i-1];
    }
    for(int i=q+1;i<n2;i++){
        R[i]=A[q+i];
    }
    int j=0,k=0,m=p;
    while(j<n1 && k<n2){
        if(L[j]<R[k]){
            A[m++]=L[j++];
        }
        else{
            A[m++]=R[k++];
        }
    }
    while(m<r){
        if(j<n1){
            A[m++]=L[j++];
        }
        else{
            A[m++]=R[k++];
        }
    }
    delete L;
    delete R;
}

void mergesort(int A[],int p,int r){
    int q;
    if(p>r){
        q=(p+r)/2;
        mergesort(A,p,q);
        mergesort(A,q+1,r);
    }
    merge(A,p,q,r);
}

int main(){
    int A[]={2,7,4,3,8,9};
    mergesort(A,0,5);
    for(int i=0;i<5;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}