#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void func(int n){
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    int temp=4;
    while(temp<n){
    	v.push_back(temp);
        for(int i=0;v[i]<temp/2;i++){
            if(temp+v[i]<n)
                v.push_back(temp+v[i]);
            else 
                break;
        }
        temp=temp*2;
    }
    for(int i=0;i<v.size();i++){
        if(v[i]<=n)
            cout<<v[i]<<' ';
    }
return;
}

int main()
{
    int n;
    cin>>n;
    func(n);
    return 0;
}
