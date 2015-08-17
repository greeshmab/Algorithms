#include <iostream>
using namespace std;

int min(int a,int b,int c){
	int k=(a<b)?a:b;
	return ((k<c)?k:c);
}

int editdis(string s,string t){
	int n=s.size();
	int m=t.size();
	int tab[n+1][m+1];
	int i=0,j=0,top,corner,left;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++)tab[i][j]=-1;
	}
	
	for(i=0;i<=n;i++){
		tab[i][0]=i;
	}
	
	for(j=0;j<=m;j++){
		tab[0][j]=j;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			top=tab[i-1][j]+1;
			left=tab[i][j-1]+1;
			if(s[i-1]!=t[j-1]){
				corner=tab[i-1][j-1]+1;
			}
			else corner=tab[i-1][j-1];
			tab[i][j]=min(top,left,corner);
		}
	}
	return tab[n][m];
}

int main() {
	string s,t;
	cin>>s>>t;
	cout<<editdis(s,t);
	return 0;
}
