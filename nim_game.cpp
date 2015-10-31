#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int res=arr[0];
    for(int i=1;i<n;i++){
        res=res^arr[i];
    }
    int temp=res;
    if(res==0){
        cout<<"YOU LOSE"<<'\n';
    }
    else{
        for(int i=0;i<n;i++){
            temp=res;
            if((temp^arr[i]) <= arr[i]){
                cout<<"TAKE "<<(temp^arr[i])<<" STONES FROM PILE "<<i+1<<'\n';
                break;
            }
        }
    }
    return 0;
}
