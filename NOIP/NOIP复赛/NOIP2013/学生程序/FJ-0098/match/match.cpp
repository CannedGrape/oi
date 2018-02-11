#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
struct data
{
       long long s,pos;
       data()
       {s=0;pos=0;}
}a[100010],b[100010];
int cmp(const data &p,const data &q)
{
    if(p.s>q.s)return 0;
    else if(p.s<q.s)return 1;
    else
    {
        if(p.pos>q.pos)return 0;
        else return 1;
    }
}
long long ans=0,n;
using namespace std;
int main()
{
   freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
  memset(a,0,sizeof(a));memset(b,0,sizeof(b));
cin>>n;
    for(int i=0;i<=n-1;i++){
        cin>>a[i].s;a[i].pos=i;}
    for(int i=0;i<=n-1;i++){
        cin>>b[i].s;b[i].pos=i;}
    sort(a,a+n,cmp);sort(b,b+n,cmp);
int j=0;
while(a[j].pos==b[j].pos)j++;
int bstart=j;
for(;j<=n-1;j++)
{
    int times=0;
    if(a[j].pos==b[bstart].pos)
    {
        bstart++;
        while(b[bstart].pos==-1)bstart++;
    }
    for(int k=bstart;k<=n-1;k++){
            if(a[j].pos==-1)times++;
       if(b[k].pos==a[j].pos)
       {
           ans+=k-bstart-times;ans=ans%99999997;b[k].pos=-1;
           break;
       }            }
}
cout<<ans<<endl;
    return 0;
}
