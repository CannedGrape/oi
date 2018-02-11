#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
char a[10000000];
int main(){
	long long p=0,q;
    int i,j,k;
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    cin>>a;
    long long q1,q2,w;
    for(i=0;a[i]!=0;i++);
    a[i]='+';
    for(i=0;a[i]!=0;i++){
        if(a[i]=='+'){
            for(j=i-1,k=1,q=0;a[j]!='+'&&a[j]!='*'&&j>=0;j--,k=k*10)
                q=q+(a[j]-'0')*k;
            w=q;
            while(a[j]=='*'){
                for(j=j-1,k=1,q=0;a[j]!='+'&&j>=0;j--,k=k*10)
                    q=q+(a[j]-'0')*k;
                w=w*q;
            }
            p=p+w;
        }
    }
    cout<<p%10000;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
