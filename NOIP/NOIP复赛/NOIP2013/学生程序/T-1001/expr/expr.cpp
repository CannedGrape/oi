#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    char a[2079999];
    int i,n,s;
    while(cin>>a[i]){
        i++;
    }
    n=i;
    s=0;
    for(i=1;i<=n;i++){
        if(a[i]=='+'){
            if(a[i+2]=='*'){
                 s=s+a[i+1]*a[i+3];
                 s=s+a[i-1];
            }
            else s=s+a[i-1]+a[i+1];
         }
         if(a[i]=='*')s=s+a[i-1]*a[i+1];
    }
    s=s%10000;
    if(s/1000==0) s=s%1000;
    if(s/100==0) s=s%100;
    if(s/10==0) s=s%10;
    cout<<s<<endl;
    return 0;
}
