#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<ctime>
#define N int(1e05+10)
#define mod 99999997
using namespace std;
struct jh
{
       int no,zhi;
       }tem[N];
int a[N],b[N],wa[N],wb[N];
int q[N],z[N];
void add(int x,int y,int zhi)
{
     for(int i=x;i<=N;i+=(i&(-i)))
     q[i]+=zhi;
     for(int i=y;i<=N;i+=(i&(-i)))
     z[i]+=zhi;
     return;
     }
int sumq(int x)
{
    int tem=0;
    for(int i=x;i>=1;i-=(i&(-i)))
    tem+=q[i];
    return tem;
    }
int sumz(int x)
{
    int tem=0;
    for(int i=x;i>=1;i-=(i&(-i)))
    tem+=z[i];
    return tem;
    }
bool cmp(const jh &x,const jh &y)
{
     return x.zhi<y.zhi;
     }
int main()
{
    freopen("match.in","r",stdin);freopen("match.out","w",stdout);
    int n;
    int ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
     scanf("%d",&a[i]);
     tem[i].zhi=a[i];
     tem[i].no=i;
     }
    sort(tem+1,tem+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
            a[tem[i].no]=i;
            wa[i]=tem[i].no;
            }
    for(int i=1;i<=n;i++)
    {
     scanf("%d",&b[i]);
     tem[i].zhi=b[i];
     tem[i].no=i;
     }
    sort(tem+1,tem+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
            b[tem[i].no]=i;
            wb[i]=tem[i].no;
            }
    for(int i=1;i<=n;i++)
    {
            if(wa[i]>wb[i])
            {
                      ans=(ans+wa[i]-wb[i])%mod;
                      add(wb[i],wa[i],1);
                      }
            }
    for(int i=1;i<=n;i++)
    {
            if(wa[i]<=wb[i])
            {
                      ans=(ans+abs(wb[i]-wa[i]-(sumq(wb[i])-sumz(wa[i]-1))))%mod;
                      }
            }
    cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
    }
