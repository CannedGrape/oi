#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<ctime>
#define N int(1e04+10)
#define M int(5e05+10)
using namespace std;
struct bian
{
       int zhi,x,y;
       }z[M];
int tim[N],fa[N];
int ans[30001],xw[30001][3];
int dl[3*N];
int dis[N];
     bool cmp(const bian &x,const bian &y)
{
     return x.zhi>y.zhi;
     }
int find(int x)
{
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
    }
int main()
{
    freopen("truck.in","r",stdin);freopen("truck.out","w",stdout);
    int n,m,q;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
     fa[i]=i;
    for(int i=1;i<=m;i++)
    {
            scanf("%d%d%d",&z[i].x,&z[i].y,&z[i].zhi);
            }
    sort(z+1,z+m+1,cmp);
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
            scanf("%d%d",&xw[i][1],&xw[i][2]);
            xw[i][0]=i;
            }
    for(int i=1;i<=m;i++)
    {
            int fx,fy;
            fx=find(z[i].x);fy=find(z[i].y);
            if(fx!=fy)
            {
                      for(int j=1;j<=q;j++)
                      {
                              int tem1,tem2;
                              tem1=find(xw[j][1]);tem2=find(xw[j][2]);
                              if(tem1==fx&&tem2==fy)
                               ans[xw[j][0]]=z[i].zhi;
                               swap(tem1,tem2);
                               if(tem1==fx&&tem2==fy)
                               ans[xw[j][0]]=z[i].zhi;
                              }
                      fa[fx]=fy;
                      }
            }
    for(int i=1;i<=q;i++)
    {
            int x,y,fx,fy;
            x=xw[i][1];y=xw[i][2];
            fx=find(x);fy=find(y);
            if(fx!=fy)
            {
                      printf("-1\n");
                      }
            else
            printf("%d\n",ans[i]);
            }
    fclose(stdin);fclose(stdout);
    return 0;
    }
