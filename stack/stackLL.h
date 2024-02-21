// using linked list
template<typename T>
// LL node
class Node{
public:
    T data;
    Node<T>* next;

    Node(T d){
        data=d;
    }
};

template<typename T>
class Stack{
    Node<T>* head;
public:
    Stack(){
        head=nullptr;
    } 

    void push(T data){
        Node<T>* temp=new Node<T>(data);
        temp->next=head;
        head=temp;
    }

    void pop(){
        if(head!=nullptr){
            Node<T>* temp=head;
            head=head->next;
            delete temp;
        }
    }

    bool empty(){
        if(head==nullptr){
            return true;
        }
        return false;
    }

    T top(){
        return head->data;
    }
};
