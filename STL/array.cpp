#include <iostream>
#include <array>
using namespace std;

int main (){
  array<int,5> myarray = { 2, 16, 77, 34, 50 };
  // array::begin example
  cout << "begin(): ";
  auto it1 = myarray.begin();
  cout<< ' ' << *it1<<'\n';
  
  // array::end example
  cout << "end(): ";
  auto it2 = myarray.begin();
  cout<< ' ' << *it2<<'\n';
  
  // array::rbegin example
  cout << "rbegin(): ";
  auto it3 = myarray.rbegin();
  cout<< ' ' << *it3<<'\n';
  
  // array::rend example
  cout << "rend(): ";
  auto it4 = myarray.rend()-1; //returns end from endside (one position before begin of array)
  cout<< ' ' << *it4<<'\n';
  
  // array::rend example
  cout << "cend(): ";
  auto it5 = myarray.cend()-1; //returns end+1 (one position ahead of end)
  cout<< ' ' << *it5<<'\n';

  cout<<myarray.front()<<" "<<myarray.empty()<<" "<<myarray.max_size()<<" ";

  

  return 0;
}