#include<iostream>
using namespace std;

struct node{
  char data;
  node*left;
  node*right;
};

struct stackNode{
  node*Node;
  stackNode*next;
  int flag;
};

class Stack{
  stackNode*top;
  public:
    Stack(){
      top=NULL;
    }
    void push(node*p){
      stackNode*ptr=new stackNode;
      ptr->Node=p;
      ptr->next=top;
      top=ptr;
    }
    
    void push(node*p,int f){
      stackNode*ptr=new stackNode;
      ptr->Node=p;
      ptr->next=top;
      top=ptr;
      top->flag=f;
    }
    
    node* pop(){
      stackNode*ptr=top;
      top=top->next;
      node*r=ptr->Node;
      delete ptr;
      return r;
    }
    
    int topflag(){
      return top->flag;
    }
    
    bool is_empty(){
      if(top==NULL){
        return true;
      }
      else{
        return false;
      }
    }
};

void nr_preorder(node*t){
  Stack s;
  while(t!=NULL){
    cout<<t->data;
    s.push(t);
    t=t->left;
  }
  while(!s.is_empty()){
    t=s.pop();
    t=t->right;
    while(t!=NULL){
      cout<<t->data;
      s.push(t);
      t=t->left;
    }
  }
}

void nr_inorder(node*t){
  Stack s;
  while(t!=NULL){
    s.push(t);
    t=t->left;
  }
  while(!s.is_empty()){
    t=s.pop();
    cout<<t->data;
    t=t->right;
    while(t!=NULL){
      s.push(t);
      t=t->left;
    }
  }
}

void nr_postorder(node*t){
  Stack s;
  while(t!=NULL){
    s.push(t,0);
    t=t->left;
  }
  while(!s.is_empty()){
    if(s.topflag()==0){
      t=s.pop();
      s.push(t,1);
      t=t->right;
      while(t!=NULL){
        s.push(t,0);
        t=t->left;
      }
    }
    else if(s.topflag()==1){
      t=s.pop();
      cout<<t->data;
    }
  }
}

void preorder(node*p){
  if(p!=NULL){
    cout<<p->data;
    preorder(p->left);
    preorder(p->right);
  }
}

void postorder(node*p){
  if(p!=NULL){
    postorder(p->left);
    postorder(p->right);
    cout<<p->data;
  }
}

void inorder(node*p){
  if(p!=NULL){
    inorder(p->left);
    cout<<p->data;
    inorder(p->right);
  }
}

node* postTree(string str){
  Stack s;
  int n=str.length();
  for(int i=0;i<n;i++){
    node*ptr=new node;
    ptr->data=str[i];
    if(isalnum(str[i])){
      ptr->left=NULL;
      ptr->right=NULL;
      s.push(ptr);
    }
    else{
      ptr->right=s.pop();
      ptr->left=s.pop();
      s.push(ptr);
    }
  }
  return s.pop();
}

node* preTree(string str){
  Stack s;
  int n=str.length();
  for(int i=n-1;i>=0;i--){
    node*ptr=new node;
    ptr->data=str[i];
    if(isalnum(str[i])){
      ptr->left=NULL;
      ptr->right=NULL;
      s.push(ptr);
    }
    else{
      ptr->left=s.pop();
      ptr->right=s.pop();
      s.push(ptr);
    }
  }
  return s.pop();
}

void display(node*ans){
  preorder(ans);
  cout<<" Preorder Recursive"<<'\n';
  inorder(ans);
  cout<<" Inorder Recursive"<<'\n';
  postorder(ans);
  cout<<" Postorder Recursive"<<'\n'<<'\n';
  nr_preorder(ans);
  cout<<" Preorder Non-Recursive"<<'\n';
  nr_inorder(ans);
  cout<<" Inorder Non-Recursive"<<'\n';
  nr_postorder(ans);
  cout<<" Postorder Non-Recursive";
}

int main(){
  int n=0;
  node*ans=NULL;
  do{
    cout<<'\n'<<"Options:-"<<'\n';
    cout<<"1. Postfix to Tree"<<'\n';
    cout<<"2. Prefix to Tree"<<'\n';
    cout<<"3. Display"<<'\n';
    cout<<"4. Exit."<<'\n';
    cin>>n;
    switch(n){
      case 1:
        {
          cout<<"Enter Postfix Expression: ";
          string postfix;
          cin>>postfix;
          ans=postTree(postfix);
          break;
        }
      case 2:
        {
          cout<<"Enter Prefix Expression: ";
          string prefix;
          cin>>prefix;
          ans=preTree(prefix);
          break;
        }
      case 3:
        {
          cout<<'\n';
          display(ans);
          cout<<'\n';
          break;
        }
      case 4:
        {
          cout<<"Exit!!"<<'\n';
          break;
        }  
    }  
  }while(n!=4);
  return 0;
}