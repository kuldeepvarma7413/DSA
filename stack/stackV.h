#include<vector>
using namespace std;
template<typename T>
class StackV{
    vector<T> arr;
public:
    void push(T data){
        arr.push_back(data);
    }
    void pop(){
        arr.pop_back();
    }
    bool empty(){
        return arr.size()==0;
    }
    T top(){
        return arr[arr.size()-1];
    }
};