#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,mm,tot,ans,first[20001],next[1000001],end[1000001],num[1000001];
bool p[1000001];
int add(int x,int y,int z)
{
    tot++;
    next[tot]=first[x];
    first[x]=tot;
    end[tot]=y;
    num[tot]=z;
}
int get(int x)
{
    if (x%2==1) return x+1;
    else return x-1;
}
int bfs(int x,int y,int z)
{
    int i,t,o=0;
    if (x==y) return 1;
    i=first[x];
    while (i!=0)
    {
      t=end[i];
      if (num[i]>=z&&p[i]==0)
      {
        p[i]=1;p[get(i)]=1;
        o=bfs(t,y,z);
        if (o==1) break;
      }
      i=next[i];
    }
    return o;
}
int check(int x,int y,int z)
{
    memset(p,0,sizeof(p));
    return bfs(x,y,z);
}
int work(int x,int y)
{
    int l,r,mid;
    ans=-1;
    l=0;r=100000;
    while (l<=r)
    {
      mid=(l+r)/2;
      if (check(x,y,mid)==1)
      {
        ans=mid;
        l=mid+1;
      }
      else
        r=mid-1;
    }
    printf("%d\n",ans);
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int i,x,y,z;
    cin>>n>>m;
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d",&x,&y,&z);
      add(x,y,z);
      add(y,x,z);
    }
    cin>>mm;
    for (i=1;i<=mm;i++)
    {
      scanf("%d%d",&x,&y);
      work(x,y);
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
