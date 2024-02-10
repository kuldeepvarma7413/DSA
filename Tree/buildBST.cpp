#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node*right;

	Node(int d){
		data = d;
		left = right = NULL;
	}
};

void printTree(Node *root);
void levelOrderPrint(Node *root);

// insert data in BST
Node* insert(Node* root, int data){
    if(root==NULL){
        return new Node(data);
    }
    if(data > root->data){
        root->right=insert(root->right, data);
    }else{
        root->left=insert(root->left, data);
    }
    return root;
}
// Should Read Input and Recursively build the tree
Node* buildBST(){

	int d;
	cin>>d;

	Node * root = NULL;
	while(d!=-1){
        root=insert(root, d);
        cin>>d;
    }
	return root;
}

// O(height)
bool search(Node* root, int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(root->data > key){
        return search(root->left, key);
    }else{
        return search(root->right, key);
    }
    return false;
}

// delete a node
Node* remove(Node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        // leaf node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }else if(root->left==NULL || root->right==NULL){
        // single child
            if(root->left==NULL){
                Node* temp=root->right;
                delete root;
                return temp;
            }else{
                Node* temp=root->left;
                delete root;
                return temp;
            }
        }else{
        // two child
            Node* temp=root->right;
            // find smalest in right tree (left most of right tree)
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->data = temp->data;
            root->right=remove(root->right, temp->data);
            return root;
        }
    }else if(root->data > key){
        root->left=remove(root->left, key);
    }else{
        root->right=remove(root->right, key);
    }
}


int main(){
	//1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
	Node *root = buildBST();
	// printTree(root);
	// levelOrderPrint(root);

	cout<< search(root,7);

	return 0;
}





void printTree(Node *root){
	if(root==NULL){
		return;
	}
	
	printTree(root->left);
	cout<<root->data<<" ";
	printTree(root->right);
}

void levelOrderPrint(Node *root){
	//BFS 
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node *temp = q.front();

		if(temp==NULL){
			q.pop();
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			q.pop();
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
		
	}
	return;
}