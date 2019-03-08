#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,q,x,b[100];
long long a[100],p=1;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int i;
    scanf("%d%d%d%d",&n,&m,&x,&q);
    a[1]=10%n;
    b[1]=1;
    for(i=2;b[i-1]*2<=x;i++)
      {
       a[i]=(a[i-1]*a[i-1])%n;
       b[i]=b[i-1]*2;
      }
    for(i--;i>=1;i--)
      if(b[i]<=x)
        {
         x-=b[i];
         p=(p*a[i])%n;
        }
    p=(p*m+q)%n;
    cout<<p<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
