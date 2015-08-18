#include <iostream>
using namespace std;

int bition(int arr[],int n){
	int i,j;
	int* lis=new int[n];
	int* lds=new int[n];
	
	for(i=0;i<n;i++){
		lis[i]=1;
		lds[i]=1;
	}
	
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(arr[i]>arr[j]  && (lis[i]<(lis[j]+1)))
				lis[i]=lis[j]+1;
		}
	}
	
	for(i=n-2;i>=0;i++){
		for(j=n-1;j>i;j++){
			if(arr[i]>arr[j]  && (lds[i]<lds[j]+1))
				lds[i]=lds[j]+1;
		}
	}
	
	int res=lis[0]+lds[0]-1;
	
	for(i=1;i<n;i++){
		if(res<(lis[i]+lds[i]-1))
			res=lis[i]+lds[i]-1;
	}
	//delete  lis;
	//delete  lds;
	return res;
}

int main() {
	int arr[]={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int n=16;
	cout<<bition(arr,n);
	return 0;
}
