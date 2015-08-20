#include <iostream>
using namespace std;

struct stack{
	int *arr;
	int capacity;
	int top;
};

struct stack* create(int cap){
	struct stack* s=new struct stack;
	if(!s)
		return NULL;
	int *arr=new int[cap];
	s->arr=arr;
	s->capacity=cap;
	s->top=-1;
	if(!s->arr)
		return NULL;
	return s;
}

int isempty(struct stack* s){
	return (s->top==-1);
}

int peek(struct stack* s){
	return s->arr[s->top];
}

void push(struct stack* s,int ele){
	s->top=ele;
	return;
}

char pop(struct stack* s){
	if(!isempty(s))
		return s->arr[s->top--];
	else 
		return '$';
}

bool isoperand(char ch){
	if( (ch>='A' && ch<='Z') || (ch>='a' && ch<='b'))
		return true;
	else return false;
}

int precedence(char op){
	switch(op){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}

int infixtopost(char* e){
	int n=sizeof(e)/sizeof(char);
	struct stack* st=create(n);
	int *ex=new int[n];
	if(!st)
		return -1;
	int i,k;
	for(i=0,k=-1;(e[i]);i++){
		if(isoperand(e[i]))
			ex[++k]=e[i];
		if(e[i]=='(')
			push(st,e[i]);
		else if(e[i]==')'){
			while(!isempty(st) && peek(st)!='(')
				ex[++k]=pop(st);
			if(!isempty(st) && peek(st)!='(')
				return -1;
			else 
				pop(st);
		}
		else {
			while(precedence(peek(st))>precedence(e[i]))
				ex[i]=pop(st);
			push(st,e[i]);
		}
	}
	while(!isempty(st))
		ex[++k]=pop(st);
	ex[++k]='\0';
	for(i=0;i<n;i++){
		cout<<ex[i];
	}
	return 0;
}
int main() {
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixtopost(exp);
	return 0;
}
