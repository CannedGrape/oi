//match joke
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[10000],b[10000],sum,num;
int a1[10000],b1[10000];
void init()
{
     scanf("%d",&n);
     for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
     for(int i=0;i<n;i++)
       scanf("%d",&b[i]);
     return;
}
void copy()
{
     for(int i=0;i<n;i++)
       {a1[i]=a[i];
        b1[i]=b[i];}
     return;
}
void ty(int i)
{
     if(i==n)
       return;
     if(abs(a[i]-b[i])>=abs(a[i]-b[i+1]))
       {swap(b[i],b[i+1]);
        sum++;}
     if(abs(a[i]-b[i])>=abs(a[i+1]-b[i]))
       {swap(a[i],a[i+1]);
        sum++;}
     return ty(i+1);
}
void rety(int i)
{
     if(i==0)
       return;
     if(abs(a1[i]-b1[i])>=abs(a1[i]-b1[i-1]))
       {swap(b1[i],b1[i-1]);
        num++;}
     if(abs(a1[i]-b1[i])>=abs(a1[i-1]-b1[i]))
       {swap(a1[i],a1[i-1]);
        num++;}
     return rety(i-1);
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    init();
    ty(0);
    rety(n);
    if(num>sum)
      cout<<sum;
    else
      cout<<num;
    return 0;
}
