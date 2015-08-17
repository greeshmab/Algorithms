#include <iostream>
using namespace std;

#define R 3
#define C 3

int min (int a,int b, int c){
	int k=((a<b)?a:b);
	return ((k<c)?k:c);
}

int mincost(int arr[R][C],int n,int m){
	int cost[n][m];
	int i=0,j=0;
	cost[0][0]=arr[0][0];
	for(i=1;i<n;i++){
		cost[i][0]=cost[i-1][0]+arr[i][0];
	}
	for(i=1;i<m;i++){
		cost[0][i]=cost[0][i-1]+arr[0][i];
	}
	
	for(i=1;i<n;i++){
		for(j=1;j<m;j++){
			cost[i][j]=min(cost[i-1][j-1],cost[i-1][j],cost[i][j-1]);
			cost[i][j]+=arr[i][j];
		}
	}
	
	return cost[n-1][m-1];
}

int main() {
	int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
	cout<<mincost(cost,2,3);
	return 0;
}
