#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MaxN 100010
#define lowbit(x) (x&(-x))
int n,i,Ans;
int c[MaxN],a[MaxN],b[MaxN],posi[MaxN],que[MaxN];
inline void Modify(int k,int x)
{
  for (;k<=n;k+=lowbit(k)) c[k]+=x;
}
inline int Query(int k)
{
  int ans=0;
  for (;k;k-=lowbit(k)) ans+=c[k];
  return(ans);
}
int main()
{
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  scanf("%d",&n);
  for (i=1;i<=n;++i) scanf("%d",&a[i]);
  for (i=1;i<=n;++i) scanf("%d",&b[i]);
  memcpy(que,a,sizeof(que));
  std::sort(que+1,que+n+1);
  for (i=1;i<=n;++i) 
  {
    a[i]=std::lower_bound(que+1,que+n+1,a[i])-que;
    posi[a[i]]=i;
  }
  memcpy(que,b,sizeof(que));
  std::sort(que+1,que+n+1);
  for (i=1;i<=n;++i)
    b[i]=posi[std::lower_bound(que+1,que+n+1,b[i])-que];
  for (i=n;i>=1;--i)
  {
    Ans=Ans+Query(b[i]);
    if (Ans>=99999997) Ans-=99999997;
    Modify(b[i],1);
  }
  printf("%d\n",Ans);
  return 0;
}
