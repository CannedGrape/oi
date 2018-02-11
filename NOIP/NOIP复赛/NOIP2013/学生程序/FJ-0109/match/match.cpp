#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct data{
       int h,num;
}a[100010],b[100010];
int t1[100010],t2[100010];
int duiying[100010];
int ans;
int n;

bool cmp (data x,data y)
{
     return x.h<y.h;
}

void init ()
{
     int i;
     cin>>n;
     for (i=1;i<=n;i++)
     {
         scanf ("%d",&a[i].h);
         a[i].num=i;
     }
     for (i=1;i<=n;i++)
     {
         scanf ("%d",&b[i].h);
         b[i].num=i;
     }
     sort (a+1,a+1+n,cmp);
     sort (b+1,b+1+n,cmp);
     for (i=1;i<=n;i++)
     {
         t1[i]=a[i].num;
         t2[b[i].num]=i;
         //t2[i]=b[i].num;
     }
     /*for (i=1;i<=n;i++)
       cout<<t1[i]<<" ";
     cout<<endl;
     for (i=1;i<=n;i++)
       cout<<t2[i]<<" ";*/
}

int myabs (int x)
{
    if (x>=0)  return x;
    return -x;
}

void doing ()
{
     int i;
     ans=0;
     for (i=1;i<=n;i++)
     {
       if (i!=t2[t1[i]])
       {
         ans=ans+(2*myabs(i-t2[t1[i]])-1)%99999997;
         ans=ans%99999997;
       }
     }
     ans=ans/2;
     cout<<ans<<endl;
     /*for (i=1;i<=n;i++)
       cout<<t1[i]<<" ";
       cout<<endl;
     for (j=1;j<=n;j++)
       cout<<t2[j]<<" ";*/
}

int main ()
{
    freopen ("match.in","r",stdin);
    freopen ("match.out","w",stdout);
    init ();
    doing ();
    //system ("pause");
    return 0;
}
