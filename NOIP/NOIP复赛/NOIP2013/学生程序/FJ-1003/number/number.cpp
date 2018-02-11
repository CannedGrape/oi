#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,p,a[1000001];
long long b[1000001],c[1000001],t;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i;
    scanf("%d%d",&n,&p);
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    b[1]=a[1];
    for(i=2;i<=n;i++)
      if(b[i-1]>0)
        b[i]=a[i]+b[i-1];
      else
        b[i]=a[i];
    c[1]=b[1];
    t=2*b[1];
    for(i=2;i<=n;i++)
      {
       c[i]=t;
       if(b[i]+c[i]>t)
         t=b[i]+c[i];
      }
    if(c[1]>c[n])
      cout<<c[1]%p<<"\n";
    else
      cout<<c[n]%p<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
