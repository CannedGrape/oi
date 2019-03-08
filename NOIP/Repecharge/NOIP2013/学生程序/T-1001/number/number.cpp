#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,p,i,x;
    int s[n+1],t[n+1],f[n+1];
    cin>>n>>p;
    for(i=1;i<=n;i++){
        cin>>s[i];
    }
    t[1]=s[1];
    f[1]=t[1];
    x=f[1];
    for(i=2;i<=n;i++){
        t[i]=s[i]+t[i-1];
        f[i]=t[i-1]+f[i-1];
        if(f[i]>=x)
            x=f[i];
    }
    cout<<x%p<<endl;
    return 0;
}
