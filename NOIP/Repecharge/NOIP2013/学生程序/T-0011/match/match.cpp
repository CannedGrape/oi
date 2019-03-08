#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,a[100001],b[100001],c[100001],d[100001],p;
inline void kp(int t,int w)
{
       swap(b[(t+w)/2],b[t]);
       swap(c[(t+w)/2],c[t]);
       int i=t+1,j=w;
       while(i<j)
         {
          while(b[i]<b[t] && i<=w)
            i++;
          while(b[j]>b[t] && j>t)
            j--;
          if(i<j)
            {
             swap(b[i],b[j]);
             swap(c[i],c[j]);
             i++;
             j--;
            }
         }
       while(b[j]>b[t] && j>t)
         j--;
       if(t<j)
         {
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
       swap(d[(t+w)/2],d[t]);
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
             swap(d[i],d[j]);
             i++;
             j--;
            }
         }
       while(a[j]>a[t] && j>t)
         j--;
       if(t<j)
         {
          swap(a[t],a[j]);
          swap(d[t],d[j]);
         }
       if(t<j-1)
         kp2(t,j-1);
       if(j+1<w)
         kp2(j+1,w);
}
inline void gb(int t,int w)
{
       if(t==w)
         return;
       int i,j,m=(t+w)/2;
       gb(t,m);
       gb(m+1,w);
       for(i=t;i<=m;i++)
         b[i-t+1]=a[i];
       for(i=m+1;i<=w;i++)
         c[i-m]=a[i];
       for(i=1,j=1;i<=m-t+1 && j<=w-m;)
         if(b[i]<c[j])
           a[t+i+j-2]=b[i++];
         else
           {
            a[t+i+j-2]=c[j++];
            p=(p+m-t-i+2)%99999997;
           }
       for(;i<=m-t+1;i++)
         a[t+i+j-2]=b[i];
       for(;j<=w-m;j++)
         a[t+i+j-2]=c[j];
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      {
       scanf("%d",&b[i]);
       c[i]=d[i]=i;
      }
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    kp(1,n);
    kp2(1,n);
    for(i=1;i<=n;i++)
      a[d[i]]=c[i];
    gb(1,n);
    printf("%d\n",p);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
