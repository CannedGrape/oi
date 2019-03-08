#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<cstdlib>
using namespace std;
int n,m,k,x,temp,s,ans,a;
int gcd(int x,int y)
{
    int t;
    t=x%y;
    if(t==0)
    return y;
    else
    if(y==1)
    return y;
    else  
     return   gcd(y,t);
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
  int i,j=0;
     scanf("%d%d%d%d",&n,&m,&k,&x);
     j=gcd(n,m);
    temp=n/j;
     s=1;
     j=10%temp;
     for(i=1;i<=k;i++)
     {
         s=s*j;
         s=s%temp;
     }
     for(i=1;i<=s;i++)
     {
           x=x+m;
           if(x>=n)
           x=x-n;
     }
     printf("%d",x);
  fclose(stdin);
  fclose(stdout);
  return 0;
}

