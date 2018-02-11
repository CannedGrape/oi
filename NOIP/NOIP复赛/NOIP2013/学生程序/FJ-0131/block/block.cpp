#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100000],n,m,num,sum,k;
void init()
{
     scanf("%d",&n);
     for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
     return;
}
void se()
{
     num=0;
     int h,t;
     for(int i=0;i<n;i++)
       {if(a[i]!=0)
          {h=i;
           break;}}
     for(int i=n;i>0;i--)
       {if(a[i]!=0)
           {t=i;
            break;}}
     for(int i=h;i<t;i++)
       {if(a[i]==0&&a[i+1]!=0)
          num++;}
     return;
}
void xuzhao()
{
     m=99999;
     for(int i=0;i<n;i++)
       if(a[i]<m&&a[i]!=0)
         m=a[i];
     return;
}
void pd()
{
     k=0;
     for(int i=0;i<n;i++)
       if(a[i]==0)
         k++;
     return;
}        
void ty()
{
     pd();
     if(k==n)
       return;
     xuzhao();
     se();
     for(int i=0;i<n;i++)
       {if(a[i]!=0)
          a[i]=a[i]-m;}
     sum=sum+1+num;
     ty();
     return;
}
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    init();
    ty();
    cout<<sum;
    return 0;
}
