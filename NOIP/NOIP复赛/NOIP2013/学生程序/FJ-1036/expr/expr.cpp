#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[1000001];
char b[1000001];

int main ()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    int n=0,m=0,k=1,k1=0;
    for (;;)
      {
         scanf("%d",&a[++n]);
         scanf("%c",&b[n]);
         if (int(b[n])==10) break;
      }
    for (int i=1; i<=n; ++i)
      {
        if (b[i]=='*') k=a[i];
        if (b[i-1]=='*') k=k*a[i];
        if (b[i-1]=='*' && b[i]=='+') m=m+k;
        if (b[i]=='+') k1=a[i];
        if (b[i-1]=='+') m=m+k1;
      }
    printf("%d",m);
    fclose(stdin); fclose(stdout);
}
