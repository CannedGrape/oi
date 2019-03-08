#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,x[100001],y[100001],a[10001],b[10001],c[100001],d[100001],p,m=1,l;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    if(n==0)
      m=0;
    for(i=1;i<=n;i++)
      {
       scanf("%d",&y[i]);
       if(a[y[i]]==0)
         {
          a[y[i]]=b[y[i]]=++p;
          c[p]=i;
         }
       else
         {
          d[b[y[i]]]=++p;
          c[p]=i;
          b[y[i]]=p;
         }
      }
    x[1]++;
    x[n]++;
    for(i=0;m>0;i++)
      {
       if(a[i]>0)
         for(j=a[i];;j=d[j])
           {
            if(x[c[j]]==0)
              {
               x[c[j]-1]++;
               x[c[j]+1]++;
               m++;
              }
            if(x[c[j]]==1)
              if(c[j]==1 || x[c[j]-1]==-1)
                x[c[j]+1]++;
              else
                x[c[j]-1]++;
            if(x[c[j]]==2)
              m--;
            x[c[j]]=-1;
            if(j==b[i])
              break;
           }
       l+=m;
      }
    printf("%d\n",l);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
