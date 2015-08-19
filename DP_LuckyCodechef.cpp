#include <iostream>
using namespace std;

int party(int arr[],int n){
	int i,j,max;
	int lis[n],lds[n];
	
	for(i=0;i<n;i++){
		lis[i]=1;
		lds[i]=1;
	}
	
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(arr[i]>arr[j] && lis[i]<(lis[j]+1))
				lis[i]=lis[j+1];
		}
	}
	
	for(i=n-2;i>=0;i--){
		for(j=n-1;j>i;j--){
			if(arr[i]>arr[j] && lds[i]<(lds[j]+1))
				lds[i]=lds[j+1];
		}
	}
	
	max=lis[0]+lds[0]-1;
	for(i=1;i<n;i++){
		if(max<(lis[i]+lds[i]-1))
			max=(lis[i]+lds[i]-1);
	}
	return max;	
}

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int arr[n];
		for(int j=0;j<n;j++){
			cin>>arr[j];
		}
		cout<<party(arr,n)<<'\n';
	//	delete arr;
	}
	return 0;
}
