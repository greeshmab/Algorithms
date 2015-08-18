#include <iostream>
using namespace std;

int max(int a,int b){
	return ((a>b)?a:b);
}

int longpalin(string s){
	int i,j,le;
	int n=s.size();
	if(n==1)return n;
	if(n==2 && s[0]==s[1])return n;
	int l[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			l[i][j]=0;
	}
	for(i=0;i<n;i++){
		l[i][i]=1;
	}
	for(le=2;le<=n;le++){
		for(i=0;i<(n-le+1);i++){
			j=i+le-1;
			if(s[i]==s[j] && le==2)
				l[i][j]=2;
			else if(s[i]==s[j]){
				l[i][j]=l[i+1][j-1]+2;
			}
			else 
				l[i][j]=max(l[i+1][j],l[i][j-1]);
		}
	}
	return l[0][n-1];
}

int main() {
	string s;
	cin>>s;
	cout<<longpalin(s);
	return 0;
}
