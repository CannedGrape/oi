#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge{int a,b,c;}e[50010];
int fa[50010],n,m,i,j,test,p,q,u[50010],v[50010],ans[50010],f[50010],tot;
bool cmp(edge A,edge B){return A.c>B.c;}
int find(int x){if (x==fa[x]) return x;return fa[x]=find(fa[x]);}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) fa[i]=i;
    for (i=1;i<=m;i++)  scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
    sort(e+1,e+m+1,cmp);
    scanf("%d",&test);
    for (i=1;i<=test;i++) {scanf("%d%d",&u[i],&v[i]);ans[i]=-1;f[i]=i;}
    tot=test;
    i=1;
    while (i<=m)
    {
       p=find(e[i].a);q=find(e[i].b);
       if (p!=q) fa[p]=q;
       i++;
       while (e[i].c==e[i-1].c&&i<=m)
       {
         p=find(e[i].a);q=find(e[i].b);
         if (p!=q) fa[p]=q;
         i++;
       }
       i--;
       int temp=0;
       for (j=1;j<=tot;j++)
       {
           p=find(u[f[j]]);q=find(v[f[j]]);
           if (p==q) ans[f[j]]=e[i].c;
           else {temp++;f[temp]=f[j];}
       }
       tot=temp;
       if (tot==0) break;
       i++;
    }
    for (i=1;i<=test;i++) printf("%d\n",ans[i]);
    return 0;
}
