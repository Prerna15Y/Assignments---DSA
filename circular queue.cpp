//DSA Assignment 3
//4243 Prerna Yadav
#include<bits/stdc++.h>
using namespace std;
#define r rear
#define f front
#define max 5

struct Queue{
	int r=-1,f=-1;
	int arr[max];
};
Queue q;
Queue *p=&q;

void enqueue(Queue *p,int x){
	if((p->r+1)%max==p->f){
		cout<<x<<" can not be added.Queue Overflow.Queue is full.\n";
	}
	else{
		if(p->r==-1){
			p->r=0; p->f=0;
		}
		else if(p->r==max-1){
			p->r=0;
		}
		else{
			p->r++;
		}
		p->arr[p->r]=x;
		cout<<x<<" is added to the queue.";
		cout<<"\n";
	}
}

void dequeue(Queue *p){
	int a;
	if(p->r==-1){
		cout<<"\nQueue Underflow.Queue is empty.";
	}
	else{
		a=p->arr[p->f];
		if(p->f==p->r){
			p->f=-1; p->r=-1;
		}
		else if(p->f==max-1){
			p->f=0;
		}
		else{ p->f++;}
		cout<<"\nDeletd element is : "<<a;
	}
	cout<<"\n";
}

void display(Queue *p){
	int i,j;
	if(p->r==-1){
		cout<<"\nNo elements to be displayed.Queue is empty.";
	}
	else{
		cout<<"Elements in the queue: ";
	if(p->f>p->r){
		for(i=p->f;i<max;i++){
			cout<<p->arr[i]<<" ";
		}
		for(j=0;j<=p->r;j++){
			cout<<p->arr[j]<<" ";
		}	
	}
	else{
		for(i=p->f;i<=p->r;i++){
			cout<<p->arr[i]<<" ";
		}
	}
	cout<<"\n";
	}
}

int main(){
	enqueue(p,5);
	enqueue(p,6);
	enqueue(p,7);
	enqueue(p,8);
	enqueue(p,9);
	enqueue(p,10);
	display(p);
	dequeue(p);
	dequeue(p);
	display(p);
	enqueue(p,10);
	enqueue(p,11);
	enqueue(p,12);
	display(p);
	dequeue(p);
	dequeue(p);
	dequeue(p);
	display(p);
	dequeue(p);
	display(p);
	dequeue(p);
	dequeue(p);
	display(p);

}




