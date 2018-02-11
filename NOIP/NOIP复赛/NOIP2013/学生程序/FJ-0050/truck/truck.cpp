#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int n,m,fa[100020],q,q1[30010],q2[30010],ans[30010];
struct edge
{
       int x,y,z;
}e[100020];
bool cmp(edge x,edge y)
{
     return (x.z>y.z);
}
int getfa(int x)
{
    if (fa[x]!=x)
       fa[x]=getfa(fa[x]);
    return fa[x];
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int i,j,f1,f2;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
        fa[i]=i;
    for (i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
    scanf("%d",&q);
    for (i=1;i<=q;i++)
        scanf("%d%d",&q1[i],&q2[i]);
    sort(e+1,e+1+n,cmp);
    for (i=1;i<=m;i++)
    {
        f1=getfa(e[i].x);
        f2=getfa(e[i].y);
        if (f1!=f2)
        {
           fa[f1]=f2;
           for (j=1;j<=q;j++)
               if (ans[j]==0)
                  if (getfa(q1[j])==getfa(q2[j]))
                     ans[j]=e[i].z;
        }
    }
    for (i=1;i<=q;i++)
    {
        if (ans[i]==0)
           printf("-1\n");
        else
           printf("%d\n",ans[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
