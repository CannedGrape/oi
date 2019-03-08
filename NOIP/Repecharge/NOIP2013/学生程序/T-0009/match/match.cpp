#include<cstdio>
#include<algorithm>
using namespace std;
struct xxx{
       int x,y;
}a[100001],b[100001];
bool f[100001];
int n;
int tot,ans;
int comp(const xxx &aa,const xxx &bb)
{
    if (aa.x<bb.x)return 1;
    else return 0;
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){scanf("%d",&a[i].x);a[i].y=i;}
    for (int i=1;i<=n;++i){scanf("%d",&b[i].x);b[i].y=i;}
    sort(a+1,a+n+1,comp);
    sort(b+1,b+n+1,comp);
    for (int i=1;i<=n;++i)
      for (int j=1;j<=n;++j)
        if (a[i].y==b[j].y)
          {a[i].x=j;b[j].x=i;}
    for (int i=1;i<=n;++i)
      if (!f[i])
        if (a[i].y==b[i].y)f[i]=true;
          else if (a[i].x=b[i].x){ans++;f[i]=true;f[a[i].x]=true;}
            else tot++;
    if (tot!=0)ans=ans+tot-1;
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
    return 0;
}
