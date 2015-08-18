#include <iostream>
using namespace std;

int max(int a,int b){
	return ((a>b)?a:b);
}

int maxval(int val[],int wt[],int n,int W){
	int k[n+1][W+1];
	int i=0,w=0;
	for(i=0;i<=n;i++){
		for(w=0;w<=W;w++){
			if(i==0 || w==0)
				k[i][w]=0;
			if(wt[i-1]<=w)
				k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
			else
				k[i][w]=k[i-1][w];
		}
	}
	return k[n][W];
	
}
int main() {
	int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n=3;
    cout<<maxval(val,wt,n,W);
    
	return 0;
}
