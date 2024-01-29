#include<bits/stdc++.h>
using namespace std;
class Student{
    string name="";
    int marks=0;
    Student(string name, int marks){
        this->name=name;
        this->marks=marks;
    }
};
int main()
{
    int n=5;
    vector<vector<Student>> arr(361, vector<Student>());
    for(int i=0; i<n; i++){
        string name;
        int marks;
        cin>>name>>marks;
        vector<Student> temp((name,marks));
    }
    for(auto a:arr){
        for(auto c:a){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return 0;
}


do it