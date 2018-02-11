#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,x[100001],f[100001],g[100001],a[100001],b[100001],p,q;
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i,j,k,l,u;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&x[i]);
    if(n<=1000)
      {
       for(i=1;i<=n;i++)
         {
          f[i]=g[i]=1;
          for(j=1;j<i;j++)
            {
             if(x[j]>x[i] && g[j]+1>f[i])
               f[i]=g[j]+1;
             if(x[j]<x[i] && f[j]+1>g[i])
               g[i]=f[j]+1;
            }
         }
       printf("%d\n",max(f[n],g[n]));
      }
    else
      {
       for(i=1;i<=n;i++)
         {
          k=0;
          for(j=1;j<=p && x[a[j]]<x[i];j++)
            if(k==0 || f[a[j]]>f[k])
              k=a[j];
          g[i]=f[k]+1;
          for(l=1,u=1;l<j;l++)
            if(x[a[l]]<x[k] || a[l]==k)
              a[u++]=a[l];
          if(u==j)
            {
             for(l=p;l>=j;l--)
               a[l+1]=a[l];
             a[u]=i;
             p++;
            }
          else
            {
             a[u++]=i;
             for(;l<=p;l++)
               a[u++]=a[l];
             p=u-1;
            }
          k=0;
          for(j=1;j<=q && x[b[j]]>x[i];j++)
            if(k==0 || g[b[j]]>g[k])
              k=b[j];
          f[i]=g[k]+1;
          for(l=1,u=1;l<j;l++)
            if(x[b[l]]>x[k] || b[l]==k)
              b[u++]=b[l];
          if(u==j)
            {
             for(l=q;l>=j;l--)
               b[l+1]=b[l];
             b[u]=i;
             q++;
            }
          else
            {
             b[u++]=i;
             for(;l<=q;l++)
               b[u++]=b[l];
             q=u-1;
            }
         }
       printf("%d\n",max(f[n],g[n]));
      }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
