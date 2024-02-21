#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
	string key;
	T value;
	Node * next;

	Node(string key,T value){
		this->key = key;
		this->value = value;
		next = NULL;
	}
	//recursive call on the next node
	~Node(){
		//cout<<"Deleting : "<<key<<endl;
	}
};

template<typename T>
class Hashtable{
	Node<T> ** table;
	int cs; 
	int ts;

	int hashFn(string key){
		int p = 1;
		int ans = 0;
		for(auto c : key){
			ans = (ans + c*p)%ts;
			p = (p*29)%ts;
		}
		return ans;
	}

	void rehash(){
		//create a table of 2x size
		// copy the data
		// delete the old table 
		Node<T>** oldTable = table;
		int oldTs = ts;
		cs = 0;
		ts = 2*ts; //you can make it prime
		table = new Node<T>*[ts];

		//new table buckets NULL init 
		for(int i=0;i<ts;i++){
			table[i] = NULL;
		} 

		//copy the data from old table to new table
		for(int i=0; i<oldTs;i++){
			Node<T> * temp = oldTable[i];
			while(temp!=NULL){
				insert(temp->key, temp->value);
				Node<T>* current = temp;
				temp = temp->next;
				delete current;
			}

		}
		delete [] oldTable;
		print();

	}


public:
	Hashtable(int defaultSize=7){
		ts = defaultSize;
		cs = 0;
		table = new Node<T>*[ts];

		//init each bucket with a NULL address (important)
		for(int i=0;i<ts;i++){
			table[i] = NULL;
		}
	}

	void insert(string key,int value){
		//1. get the index
		int index = hashFn(key);
		//Insert at that index 
		Node<T>* n = new Node<T>(key,value);
		n->next = table[index];
		table[index] = n;
		cs++;
		//load factor ...
		float load_factor = (float)cs/ts;
		if(load_factor>0.75){
			//rehash 
			// write later...
			cout<<"Load factor :"<<load_factor;
			rehash();
		}

	}

	T* search(string key){
		int index = hashFn(key);

		Node<T> * temp = table[index];
		while(temp!=NULL){
			if(temp->key==key){
				return &temp->value;
			}
			temp = temp->next;
		}


		return NULL;
	}

	void remove(string key){
		//.......hashindex --> bucket --> delete a node from the linked list --> 
		// HOMEWORK 
		
	}

	//return by reference 
	T& operator[](string key){

		T* ptr = search(key);
		if(ptr==NULL){
			T empty;
			insert(key,empty);
			ptr = search(key);
		}
		
		return *ptr; //empty 

	}

	void print(){

		//iterate over buckets
		for(int i=0;i<ts;i++){
			Node<T> * temp = table[i];
			cout<<"Bucket "<<i<<": ";
			while(temp!=NULL){
				cout<<temp->key<<" ,";
				temp = temp->next;
			}
			cout <<endl;
		}

	}

};