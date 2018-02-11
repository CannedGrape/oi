#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
       int num,w,id;
}aa[100010],bb[100010];
int wz[100010],c[100010];
int n;
long long t[300010],ans=0;
inline bool comp(sth a,sth b)
{
       return a.num<b.num;
}
inline bool cmp(sth a,sth b)
{
       return a.w<b.w;
}
int lowbit(int x)
{
    return (x & (-x));
}
void add(int x)
{
     while(x<=n)
     {
         t[x]++;
         x+=lowbit(x);
     }
}
long long ask(int x)
{
     long long now=0;
     while(x>0)
     {
               now+=t[x];
               x-=lowbit(x);
     }
     return now;
}
int main()
{
    int i;
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    memset(t,0,sizeof(t));
    scanf("%d",&n);
    for(i=1;i<=n;i++)  {scanf("%d",&aa[i].num);aa[i].w=i;}
    for(i=1;i<=n;i++)  {scanf("%d",&bb[i].num);bb[i].w=i;}
    sort(bb+1,bb+1+n,comp);
    for(i=1;i<=n;i++)  wz[i]=bb[i].w;
    sort(aa+1,aa+1+n,comp);
    for(i=1;i<=n;i++)  aa[i].id=i;
    sort(aa+1,aa+1+n,cmp);
    for(i=1;i<=n;i++)   c[i]=wz[aa[i].id];
    for(i=n;i>=1;i--)
    {
       ans=(ans+ask(c[i]-1))%99999997;
       add(c[i]);
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
