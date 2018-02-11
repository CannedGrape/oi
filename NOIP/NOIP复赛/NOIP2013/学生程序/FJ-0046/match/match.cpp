#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;
#define MOD 99999997
#define MXN 100010
#define MXX 1000010
struct node
{
       int num,pos;
}a[MXN],b[MXN],c[MXN];
int n,tt[MXX],pos[MXN];
void Init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++) {scanf("%d",&a[i].num);a[i].pos=i;}
     for(int i=1;i<=n;i++) {scanf("%d",&b[i].num);b[i].pos=i;}
}
bool cmp(node x,node y){return x.num>y.num;}
int lowbit(int x){return (x&(-x));}
void Update(int x)
{
     while(x<=n)
       {
         tt[x]++;
         x+=lowbit(x);
       }
}
int Query(int x)
{
    int tot=0;
    while(x)
      {
        tot+=tt[x];
        x-=lowbit(x);
      }
    return tot;
}
void solve()
{
     sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);
     for(int i=1;i<=n;i++) c[a[i].pos].num=i;
     for(int i=1;i<=n;i++) c[b[i].pos].pos=i;
     for(int i=1;i<=n;i++) pos[c[i].num]=i;
     for(int i=1;i<=n;i++) c[i].pos=pos[c[i].pos];
     int total=0;
     for(int i=n;i>=1;i--)
       {
         total=(total+Query(c[i].pos-1))%MOD;
         Update(c[i].pos);
       }
     printf("%d\n",total);
}
int main()
{
    freopen("match.in","r",stdin);freopen("match.out","w",stdout);
    Init();
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}
