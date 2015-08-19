#include <iostream>
using namespace std;

int lis( int arr[], int n )
{
   int *lis, i, j, max = 0;
   lis = (int*) malloc ( sizeof( int ) * n );
 
   /* Initialize LIS values for all indexes */
   for ( i = 0; i < n; i++ )
      lis[i] = 1;
    int flag=0;
   /* Compute optimized LIS values in bottom up manner */
   for ( i = 1; i < n; i++ ){
      for ( j = 0; j < i; j++ ){
        if ( (arr[i] > arr[j]) && (lis[i] < lis[j] + 1) && (flag==0)){
            lis[i] = lis[j] + 1;
            flag=1;
        }
        else if ( (arr[i] < arr[j]) && (lis[i] < lis[j] + 1) && (flag==1)){
            lis[i] = lis[j] + 1;
        	flag=0;
        }
      }
    }
   /* Pick maximum of all LIS values */
   for ( i = 0; i < n; i++ )
      if ( max < lis[i] )
         max = lis[i];
 
   return max;
}
 
/* Driver program to test above function */
int main()
{
  int arr[] = { 1, 7, 4, 9, 2, 5 };
  int n = 6;
  cout<<lis(arr,n);
  return 0;
}
