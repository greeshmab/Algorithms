#include <iostream>
using namespace std;

void activity(int s[],int f[],int n){
	int i,j;
	i=0;
	cout<<i;
	for(j=1;j<n;j++){
		if(s[j]>=f[i]){
			cout<<j<<" ";
			i=j;
		}
	}
return;

}

int main() {
	int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    activity(s,f,6);
	return 0;
}
