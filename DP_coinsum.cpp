#include <iostream>
using namespace std;

int coinsum(int arr[],int m,int n){
	int tab[n+1][m];
	int i,j,x,y;
	//base case
	for(j=0;j<m;j++){
		tab[0][j]=1;
	}
	
	for(i=1;i<n+1;i++){
		for(j=0;j<m;j++){
			//sum including arr[j]
			x=((i-arr[j])>=0)?tab[i-arr[j]][j]:0;
			//sum excluding arr[j]
			y=(j>=1)?tab[i][j-1]:0;
			tab[i][j]=x+y;
		}
	}
return tab[n][m-1];

}

int main() {
	int arr[] = {1, 2, 3};
	int m=3,n=4;
	cout<<coinsum(arr,m,n);
	return 0;
}
