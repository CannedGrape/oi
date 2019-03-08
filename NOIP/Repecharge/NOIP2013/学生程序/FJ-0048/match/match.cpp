#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

  int a[100010];
  int b[100010];
  int sa[100010];
  int sb[100010];
  int ma[100010];
  int mb[100010];
  int num[100010];
  int n,t,k,ans;

  int erfena(int l,int r)
  {
       int mid;
       
       if (l==r)
       {
                k=l;
       }
       else
       {
           mid=(l+r)/2;
           if (t>a[mid])
           {
                        erfena(mid+1,r);
           }
           if (t<a[mid])
           {
                        erfena(l,mid-1);
           }
           if (t==a[mid])
           {
                         erfena(mid,mid);
           }
       }
  }
  
  int erfenb(int l,int r)
  {
       int mid;
       
       if (l==r)
       {
                k=l;
       }
       else
       {
           mid=(l+r)/2;
           if (t>b[mid])
           {
                        erfenb(mid+1,r);
           }
           if (t<b[mid])
           {
                        erfenb(l,mid-1);
           }
           if (t==b[mid])
           {
                         erfenb(mid,mid);
           }
       }
  }
   
   
int main()
{
    int i,j,p,q,o;
    
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sa[i]=a[i];
    }
    sort(a+1,a+n+1);
    for (i=1;i<=n;i++)
    {
        t=sa[i];
        erfena(1,n);
        ma[i]=k;
    }
    for (i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        sb[i]=b[i];
    }
    sort(b+1,b+n+1);
    for (i=1;i<=n;i++)
    {
        t=sb[i];
        erfenb(1,n);
        mb[k]=i;
    }
    for (i=1;i<=n;i++)
    {
        num[i]=mb[ma[i]];
    }
    ans=0;
    for (i=1;i<=n;i++)
    {
        for (j=i;j<=n;j++)
        {
            if (num[j]==i)
            {
                          p=j;
                          break;
            }
        }
        for (q=p;q>=i+1;q--)
        {
            o=num[q];
            num[q]=num[q-1];
            num[q-1]=o;
            ans++;
            ans=ans%99999997;
        }
    }
    printf("%d",ans);
    return 0;
}
