//tree
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
class Stack{
	Node *top;
	
	public:
	Stack(){
		top=NULL;
	}
	int isEmpty(){
		if(top==NULL) return 1;
		return 0;
	}
	void push(char c){
		Node *ptr;
		ptr=new Node();
		ptr->data=c;
		ptr->next=top;
		top=ptr;
	}
	char pop(){
		Node *ptr;
		char c;
		ptr=top;
		c=ptr->data;
		top=top->next;
		delete(ptr);
		return c;
	}
	char topData(){
		return top->data;
	}
};
//Recursive Traversal
void PreOrder(struct Node* node){
    if(node==NULL){
        return;
    }
    cout<<node->data<<" ";
    PreOrder(node->left);
    PreOrder(node->right);
}

void InOrder(struct Node* node){
    if(node==NULL){
        return;
    }
    InOrder(node->left);
    cout<<node->data<<" ";
    InOrder(node->right);
}

void PostOrder(struct Node* node){
    if(node==NULL){
        return;
    }
    PostOrder(node->left);
    PostOrder(node->right);
    cout<<node->data<<" ";
}

//-------------------------------------------------------//

//Non-Recursive Traversal
void Inorder(struct Node* root){

}
int main(){

}