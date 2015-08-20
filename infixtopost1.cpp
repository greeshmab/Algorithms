#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int prec(char ch){
	switch(ch){
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

int infixtopost(string s){
	stack<char> st;
	int i,k;
	string ex;
	for(i=0,k=-1;s[i];i++){
		if(isalpha(s[i]))
			ex[++k]=s[i];
		if(s[i]=='(')
			st.push(s[i]);
	    if(s[i]==')'){
			while(!st.empty() && isalpha(s[i]))
				ex[++k]=st.top();
				st.pop();
			if(!st.empty() && isalpha(s[i]))
				return -1;
			else st.pop();
		}
		else {
			if(prec(s[i]<prec(st.top()))){	
				ex[++k]=st.top();
				st.pop();
			}
			else st.push(s[i]);
		}
	}
	
	while(!st.empty()){
		ex[++k]=st.top();
		st.pop();
	}
//	ex[++k]='\0';
	cout<<ex;
}

int main() {
	string s ("a+b*(c^d-e)^(f+g*h)-i");
	infixtopost(s);
	return 0;
}
