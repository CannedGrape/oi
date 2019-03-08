#include<iostream>
#include<stdio.h>
#define MAX (100)
using namespace std;
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    
    char
        a[MAX];
    
    char
       i,
       x;
    int
       s,
       n;
    
    cin>>x>>n>>a;
    
    for (i=1,s=0;i<=n;i++)
    {
        if (x==a[i])
        s++;
    }
    
    cout<<s;
    
    return 0;
}
