#include <cstdio>
#include <cstring>
#include <algorithm>
#define MaxN 100010
struct Node
{
  int num,posi;
}x[MaxN];
bool used[MaxN];
int n,i,p,block,Ans;
inline bool cmp(Node a,Node b)
{
  if (a.num<b.num) return(1); else return(0);
}
int main()
{
  freopen("block.in","r",stdin);
  freopen("block.out","w",stdout);
  scanf("%d",&n);
  for (i=1;i<=n;++i) 
  {
    scanf("%d",&x[i].num);
    x[i].posi=i;
  }
  std::sort(&x[1],&x[n+1],cmp);
  //for (i=1;i<=n;++i)
    //printf("%d %d\n",x[i].num,x[i].posi);
  memset(used,1,sizeof(used));
  used[0]=used[n+1]=0;
  x[0].num=0; block=1; Ans=0;
  for (i=1;i<=n;++i)
  {
    if (x[i].num!=x[i-1].num) Ans+=(x[i].num-x[i-1].num)*block;
    //printf("%d\n",block);
    p=x[i].posi; used[p]=0;
    if (used[p-1]&&used[p+1]) ++block;
    else if (!(used[p-1]||used[p+1])) --block;
  }
  printf("%d\n",Ans);
  return 0;
}
