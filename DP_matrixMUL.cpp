#include <iostream>
#include <climits>
using namespace std;

int matrixmul(int arr[], int n){
	int i,j,l,k,q;
	int tab[n][n];
	if(n<2)return 0;
	for(i=1;i<n;i++){
		tab[i][i]=0;
	}

	for(l=2;l<n;l++){
		for(i=1;i<=(n-l+1);i++){
			j=i+l-1;
			tab[i][j]=INT_MAX;
			 for (k=i; k<=j-1; k++){
			q=tab[i][k]+tab[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
			if(q<tab[i][j])
				tab[i][j]=q;
			}
		}
	
	}
return tab[1][n-1];
}

int main() {
	int arr[] = {1, 2, 3, 4};
	cout<<matrixmul(arr,4);
	return 0;
}
