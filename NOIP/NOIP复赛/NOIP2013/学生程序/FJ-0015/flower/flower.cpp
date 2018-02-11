#include <cstdio>
#include <cstring>
#include <algorithm>
#define lowbit(x) (x&(-x))
#define MaxN 100010
int c1[MaxN],c2[MaxN];
int tot,n,i;
int a[MaxN],que[MaxN];
inline int max(int a,int b)
{
  if (a>b) return(a); else return(b);
}
inline void Modify1(int k,int x)
{
  for (;k<=tot;k+=lowbit(k)) c1[k]=max(c1[k],x);
}
inline int Query1(int k)
{
  int ans=0;
  for (;k;k-=lowbit(k)) ans=max(ans,c1[k]);
  return(ans);
}
inline void Modify2(int k,int x)
{
  for (;k<=tot;k+=lowbit(k)) c2[k]=max(c2[k],x);
}
inline int Query2(int k)
{
  int ans=0;
  for (;k;k-=lowbit(k)) ans=max(ans,c2[k]);
  return(ans);
}
int main()
{
  freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  scanf("%d",&n);
  for (i=1;i<=n;++i) 
  {
    scanf("%d",&a[i]);
    que[i]=a[i];
  }
  std::sort(que+1,que+n+1);
  tot=std::unique(que+1,que+n+1)-que-1;
  for (i=1;i<=n;++i) a[i]=std::lower_bound(que+1,que+tot+1,a[i])-que;
  //for (i=1;i<=n;++i) printf("%d ",a[i]);
  //printf("\n");
  Modify1(a[1],1); Modify2(tot+1-a[1],1);
  for (i=2;i<=n;++i)
  {
    //printf("%d  fd = %d , fu = %d\n",i,Query2(tot-a[i])+1,Query1(a[i]-1)+1);
    Modify2(tot-a[i]+1,Query1(a[i]-1)+1);
    Modify1(a[i],Query2(tot-a[i])+1);
  }
  printf("%d\n",max(Query1(tot),Query2(tot)));
  return 0;
}
