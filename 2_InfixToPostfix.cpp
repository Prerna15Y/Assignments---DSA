//DSA Assignment 2
//4243 Prerna Yadav
#include<iostream>
#include<cmath>
using namespace std;
struct Node{
	char data;
	Node *next;
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

bool IsOperator(char c){
              if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' ){
	          return true;
              }
            return false;
}

bool IsOperand(char c){
	if(c >= 'A' && c <= 'Z')
                   return true;
            if(c >= 'a' && c <= 'z')
                   return true;
            if(c >= '0' && c <= '9')
                    return true;
            return false;
}

int precedence(char op){
	if(op == '+' || op == '-')
                   return 1;
            if(op == '*' || op == '/' || op == '%')
                    return 2;
            if(op == '^')
                    return 3;
            return 0;
}

bool eqlOrhigher(char op1, char op2){
	int p1 = precedence(op1);
            int p2 = precedence(op2);
            if (p1 == p2){
	       if(op1 == '^' )
                   return false;
            return true;
           }
           return (p1>p2 ? true : false);
}

void InfixToPostfix(char infix[20],char postfix[20]){
	Stack s;
	int i,j=0;
	char ch,c;
	for(i=0;infix[i]!='\0';i++){
	 ch=infix[i];
		if(ch == ' ')
                       continue;
                       else if(ch == '(')
                       s.push(ch);
                      else if(IsOperand(ch))
                      {
	                  postfix[j]=ch;
	                  j++;
                      }
                      else if(IsOperator(ch))
                      {
                              while(s.isEmpty()!=1 && eqlOrhigher(s.topData(),ch))
                              {
                                      postfix[j]=s.pop();
                                      j++;
                              }
                              s.push(ch);
                     }
                     else if(ch == ')')
                     {
                              while((c=s.pop())!= '(')
                              {
                                     postfix[j]=c;
                                     j++;
                               }
                      }
                }
                while(s.isEmpty()!=1){
	           postfix[j]=s.pop();
	           j++;
               }
               postfix[j]='\0';			
}

void reverse(char a[20],char b[20])
{
	int i,j;
	for(i=0;a[i]!='\0';i++){}
	i--;
	for(j=0;i>=0;j++,i--){
		if (a[i] == '(')
	            b[j] = ')';
                        else if (a[i] == ')')
	            b[j] = '(';
	            else b[j]=a[i];
	}
	b[j]='\0';
}
int Evaluate(int op1,int op2,char op){
	if(op=='+')
	return op1+op2;
	else if(op=='-')
	return op1-op2;
	else if(op=='*')
	return op1*op2;
	else if(op=='/')
	return op1/op2;
	else if(op=='%')
	return op1%op2;
	else if(op=='^')
	return pow(op1,op2);
	else
	return -1;
}

void Evaluate_Postfix(char postfix[20]){
	Stack s;
	int i,op1,op2,result; //left to right scanning for evaluation
	char ch;
	int x;
	for(i=0;postfix[i]!='\0';i++){
		ch=postfix[i];
		if(IsOperand(ch)){
			cout<<"Enter the value for "<<ch<<" :\n";
			cin>>x;
			s.push(char(x));
		}
		else{
			op2=s.pop();
			op1=s.pop();
			result=Evaluate(op1,op2,ch);
			s.push(char(result));
		}
	}
	result=s.pop();
	cout<<"Evaluated postfix result = "<<result;	
}

void Evaluate_Prefix(char prefix[20]){
	Stack s;
	int i,op1,op2,result; //right to left scanning for evaluation
	char ch;
	int x;
	for(i=0;prefix[i]!='\0';i++){}
	i--;
	for(;i>=0;i--){
		ch=prefix[i];
		if(IsOperand(ch)){
			cout<<"Enter the value for "<<ch<<" :\n";
			cin>>x;
			s.push(char(x));
		}
		else{
			op1=s.pop();
			op2=s.pop();
			result=Evaluate(op1,op2,ch);
			s.push(char(result));
		}	
	}
	result=s.pop();
	cout<<"Evaluated prefix result = "<<result;
}

void Menu(){

           cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
           cout<<"1 Infix to Postfix Conversion \n" ;
           cout<<"2 Infix to Prefix Conversion \n" ;
           cout<<"3 Evaluation of Postfix Expression \n" ;
           cout<<"4 Evaluation of Prefix Expression \n" ;
           cout<<"5 EXIT \n" ;
           cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ;
}

int main(){
	int choice;
	char prefix1[20],prefixreal[20];
	char infix[20],postfix[20],prefix[20];
	cout<<"\nEnter Infix Expression :";
	cin>>infix;
	Menu();
	cout<<"Enter your choice :\n";
	cin>>choice;
	cout<<'\n';
	if(choice==1){
		InfixToPostfix(infix,postfix);
                      cout<<"\nPostfix Expression : "<<postfix;
	}
	
	else if(choice==2){
		reverse(infix,prefix);
                       InfixToPostfix(prefix,prefix1);
                       reverse(prefix1,prefixreal);
                       cout<<"\nPrefix Expression : "<<prefixreal;
	}
	
	else if(choice==3){
		InfixToPostfix(infix,postfix);
		Evaluate_Postfix(postfix);
	}
	
	else if(choice==4){
		reverse(infix,prefix);
                       InfixToPostfix(prefix,prefix1);
                       reverse(prefix1,prefixreal);
		Evaluate_Prefix(prefixreal);
	}
	
	else if(choice==5){
		cout<<"Thanks.";
	}
	
	else{
		cout<<"\nInvalid choice.";
	}
}

