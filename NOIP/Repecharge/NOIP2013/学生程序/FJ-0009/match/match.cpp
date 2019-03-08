#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#define MXN 100010
#define M 99999997
using namespace std;
struct node
{
       int num,id;
}a[MXN],b[MXN];
int n;
int p[MXN],ans;
void init()
{
     scanf("%d",&n);
     for (int i=1;i<=n;i++)
     {
       scanf("%d",&a[i].num);
       a[i].id=i;
     }
     for (int i=1;i<=n;i++)
     {
       scanf("%d",&b[i].num);
       b[i].id=i;
     }
}
bool cmp(node a,node b)
{
     if (a.num<b.num)  return 1;
     return 0;
}
void prepare()
{
     sort(a+1,a+n+1,cmp);
     sort(b+1,b+n+1,cmp);
     for (int i=1;i<=n;i++)
       p[a[i].id]=b[i].id;
     //for (int i=1;i<=n;i++)
     //  cout<<p[i]<<" ";
     //cout<<endl;
}
int t[MXN],len;
void merge(int l,int r)//[l,r] ¶ÔpÅÅÐò 
{
     if (l==r)  return;
     int mid=(l+r)/2;
     merge(l,mid);merge(mid+1,r);
     len=l-1;
     int i,j;
     for (i=l,j=mid+1;i<=mid&&j<=r;)
     {
       if (p[i]<p[j])
         t[++len]=p[i++];
       if (p[i]>p[j])
       {
         t[++len]=p[j++];
         ans=(ans+mid-i+1)%M;
       }
     }
     while (i<=mid)  t[++len]=p[i++];
     while (j<=r)  t[++len]=p[j++];
     for (int i=l;i<=r;i++)
       p[i]=t[i];
}
int main ()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    init();
    prepare();
    merge(1,n);
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
    return 0;
}
    
