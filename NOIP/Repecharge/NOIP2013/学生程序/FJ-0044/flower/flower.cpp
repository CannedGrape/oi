#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,h[100010],ans=1,f[100010][2],g[100010][2],i,j;
int max(int a,int b){return a>b?a:b;}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&h[i]);
    for (i=1;i<=n;i++) f[i][1]=g[i][1]=1;
    for (i=2;i<=n;i++)
      for (j=1;j<i;j++)
      {
        if (h[i]>h[j])
        {
          f[i][0]=max(f[i][0],f[j][1]+1);
          g[i][1]=max(g[i][1],g[j][0]+1);
          ans=max(ans,max(f[i][0],g[i][1]));
        }
        if (h[i]<h[j])
        {
          f[i][1]=max(f[i][1],f[j][0]+1);
          g[i][0]=max(g[i][0],g[j][1]+1);
          ans=max(ans,max(f[i][1],g[i][0]));
        }
      }
    printf("%d\n",ans);
    return 0;
}
