#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    
    int
    a[100],
    i,
    n,
    p,
    s,
    t;
    
    cin>>n>>p;
    
    cin>>a[100];
    
    if (n==1)
    {
        s=a[1];             
    }
    else
    {
        for (i=0,s=0;i<=n;i++)
        {
            s=s+a[i-1];
        }
        s=2*s;
    }
    
    s=s%p;
    
    cout<<s<<endl;
       
    return 0;
}
