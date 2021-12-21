#include<iostream>
#include<queue>

using namespace std ;

struct node{
    int data;
    node*l;
    node*r;
};


node* insert(node*T,int x){
    node*tmp;
    tmp=new node();
    tmp->data=x;
    tmp->l=NULL;
    tmp->r=NULL;
    node*p=T;
    node*q=T;
    if(T==NULL)
        return tmp;
    else{
        while(p!=NULL){
            q=p;
            if(x<p->data)
                p=p->l;
            else if(x>p->data)
                p=p->r;
            else if(x==p->data){
                cout<<x<<" "<<"already present\n";break;
            }    
        }
        if(x<q->data)
            q->l=tmp;
        else if(x>q->data)
            q->r=tmp;
        else   
            delete tmp;     

    } 
    return T;   

}

void display(node*T){
    if(T!=NULL){
        display(T->l);
        cout<<T->data<<" ";
        display(T->r);
    }  
}
int min(node *T){
    node*tmp;
    while(T->l!=NULL)
        T=T->l;
    tmp=T;
    return tmp->data;    
}

int max(node*T){
    node * tmp;
    while(T->r!=NULL)
        T=T->r;
    tmp=T;
    return tmp->data; 
}

void search(node*T,int x){
    bool ans=true;
    while(T!=NULL){
        if(x==T->data){
            cout<<"\n Found \n";
            ans=false;
            break; 
        }
        else if(x<T->data)
            T=T->l;
        else   
            T=T->r;    
    }
    if(ans)
        cout<<"\n Not Found \n";
}

void LOT(node*T){
    queue<node*>q;
    node *p;
    q.push(T);
    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<p->data<<" ";
        if(p->l!=NULL)
            q.push(p->l);
        if(p->r!=NULL)
            q.push(p->r);   
    }
    cout<<endl;
}

void HeightofTree(node* T){
    queue<node *>q1;
    node*p;
    int h=0;
    q1.push(T);
    while(!q1.empty()){
        queue<node*>q2;
        while(!q1.empty()){
            p=q1.front();
            q1.pop();                
            if(p->l!=NULL)
                q2.push(p->l);
            if(p->r!=NULL)
                q2.push(p->r);   
        }
        q1=q2;
        h++;
    }
    cout<<"\n Height : "<<h-1<<endl;
}
int main(){
    int n;
    node*root=NULL;
    do{
        cout<<"\n"<<"Options:- \n";
        cout<<"1. Insert \n";
        cout<<"2. Display (Inorder) \n";
        cout<<"3. Minimum Element \n";
        cout<<"4. Maximum Element \n";
        cout<<"5. Search Element \n";
        cout<<"6: Traversal (level order) \n";
        cout<<"7: Height of Tree \n";
        cout<<"8: Exit\n\n";
        cin>>n;
        switch(n){
            case 1:{
                cout<<"\n"<<"Number of numbers to be inserted\n";
                int no;
                cin>>no;
                while(no--){
                    cout<<"Enter number\n";
                    int x;
                    cin>>x;
                    root=insert(root,x);
                }
                break;
            }
            case 2:{
                display(root);
                break;
            }
            case 3:{
                cout<<"\n"<<min(root)<<" is the Minimum element present\n";
                break;
            }
            case 4:{
                cout<<"\n"<<max(root)<<" is the Maximum element present\n";
                break;
            }
            case 5:{
                int x;
                cin>>x;
                search(root,x);
                break;
            }
            case 6:{
                cout<<endl;
                LOT(root);
                break;
            }
            case 7:{
                HeightofTree(root);
                break;
            }
            case 8:{
                cout<<"\n Thank you!\n";
                break;
            }
        }
    }
    while(n!=8);
}
