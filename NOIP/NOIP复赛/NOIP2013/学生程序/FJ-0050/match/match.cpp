#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define lowbit(x)  x&(-x)
using namespace std;
const long long mod=99999997;
long long n,ans=0,sum=0,l,r,s[100010];
struct pf
{
       long long num,high;
}hc1[100010],hc2[100010];
bool cmp(pf x,pf y)
{
     return (x.high<y.high);
}
void tj(long long pos)
{
     while (pos<=n)
     {
           s[pos]++;
           pos+=lowbit(pos);
     }
}
long long qh(long long pos)
{
     long long aa=0;
     while (pos>0)
     {
           aa+=s[pos];
           pos-=lowbit(pos);
     }
     return aa;
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    long long i,j,k;
    scanf("%lld",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%lld",&hc1[i].high);
        hc1[i].num=i;
    }
    for (i=1;i<=n;i++)
    {
        hc2[i].num=i;
        scanf("%lld",&hc2[i].high);
    }
    l=1;r=n;
    for (i=1;i<=n/2;i++)
        if (hc1[i].high==hc2[i].high)
        {
           tj(i);
           sum=(sum+2*(i-l)%mod)%mod;
           l++;
        }
    for (i=n;i>=n/2+1;i--)
        if (hc1[i].high==hc2[i].high)
        {
           tj(i);
           sum=(sum+2*(r-i)%mod)%mod;
           r--;
        }
    sort(hc1+1,hc1+1+n,cmp);
    sort(hc2+1,hc2+1+n,cmp);
    for (i=1;i<=n;i++)
    {
        if (hc1[i].num>hc2[i].num)
        {
           l=hc2[i].num;
           r=hc1[i].num;
        }
        else
        {
           l=hc1[i].num;
           r=hc2[i].num;
        }
        if (l!=r)
           ans=(ans+(r-l-(qh(r)-qh(l-1))))%mod;
    }
    if (ans%2==0)
       ans=ans/2;
    else
        ans=(ans+mod)/2;
    ans=(ans+sum)%mod;
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
