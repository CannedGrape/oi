#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,p,a[100001],b[100001],c[100001],d[10001],f[10001],k;
inline void kp(int t,int w)
{
       swap(a[(t+w)/2],a[t]);
       swap(b[(t+w)/2],b[t]);
       swap(c[(t+w)/2],c[t]);
       int i=t+1,j=w;
       while(i<j)
         {
          while(c[i]>c[t] && i<=w)
            i++;
          while(c[j]<c[t] && j>t)
            j--;
          if(i<j)
            {
             swap(a[i],a[j]);
             swap(b[i],b[j]);
             swap(c[i],c[j]);
             i++;
             j--;
            }
         }
       while(c[j]<c[t] && j>t)
         j--;
       if(t<j)
         {
          swap(a[t],a[j]);
          swap(b[t],b[j]);
          swap(c[t],c[j]);
         }
       if(t<j-1)
         kp(t,j-1);
       if(j+1<w)
         kp(j+1,w);
}
inline void kp2(int t,int w)
{
       swap(a[(t+w)/2],a[t]);
       swap(b[(t+w)/2],b[t]);
       swap(c[(t+w)/2],c[t]);
       int i=t+1,j=w;
       while(i<j)
         {
          while(a[i]<a[t] && i<=w)
            i++;
          while(a[j]>a[t] && j>t)
            j--;
          if(i<j)
            {
             swap(a[i],a[j]);
             swap(b[i],b[j]);
             swap(c[i],c[j]);
             i++;
             j--;
            }
         }
       while(a[j]>a[t] && j>t)
         j--;
       if(t<j)
         {
          swap(a[t],a[j]);
          swap(b[t],b[j]);
          swap(c[t],c[j]);
         }
       if(t<j-1)
         kp2(t,j-1);
       if(j+1<w)
         kp2(j+1,w);
}
inline int fa(int x)
{
       if(f[x]==x)
         return x;
       f[x]=fa(f[x]);
       return f[x];
}
inline void ss(int x,int j,int l)
{
       if(x==k)
         {
          printf("%d\n",l);
          n=1;
          return;
         }
       int i;
       for(i=d[x];i<d[x+1];i++)
         if(b[i]!=j)
           {
            if(c[i]<l)
              ss(b[i],x,c[i]);
            else
              ss(b[i],x,l);
            if(n==1)
              return;
           }
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      f[i]=i;
    for(i=1;i<=m;i++)
      scanf("%d%d%d",&a[i],&b[i],&c[i]);
    kp(1,m);
    for(i=1;i<=m;i++)
      {
       j=fa(a[i]);
       k=fa(b[i]);
       if(j!=k)
         {
          f[j]=k;
          a[++p]=a[i];
          b[p]=b[i];
          c[p]=c[i];
         }
      }
    for(i=1;i<=p;i++)
      {
       a[i+p]=b[i];
       b[i+p]=a[i];
       c[i+p]=c[i];
      }
    p*=2;
    kp2(1,p);
    for(i=p;i>=1;i--)
      d[a[i]]=i;
    d[n+1]=p+1;
    for(i=n;i>=1;i--)
      if(d[i]==0)
        d[i]=d[i+1];
    scanf("%d",&m);
    for(i=1;i<=m;i++)
      {
       scanf("%d%d",&j,&k);
       n=0;
       ss(j,0,2147483647);
       if(n==0)
         printf("-1\n");
      }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
