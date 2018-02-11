#include <cstdio>
#include <cstring>
#include <algorithm>
#define MaxN 10010
#define MaxQ 30010
#define MaxM 50010
struct edge
{
  int u,v,w;
}E[MaxM];
int Ans[MaxQ],father[MaxN],next[MaxN],last[MaxN];
int tot,head[MaxN],pre[MaxM*2],d[MaxM*2],w[MaxM*2];
int n,m,q,i,j,k,root,x,y,sum,prev;
inline bool cmp(edge a,edge b)
{
  if (a.w>b.w) return(1); else return(0);
}
inline void Add(int a,int b,int c)
{
  d[++tot]=b; pre[tot]=head[a]; w[tot]=c; head[a]=tot;
}
int find(int k)
{
  if (father[k]<0) return(k);
  else return(father[k]=find(father[k]));
}
int main()
{
  freopen("truck.in","r",stdin);
  freopen("truck.out","w",stdout);
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;++i) last[i]=i;
  for (i=1;i<=m;++i)
    scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
  std::sort(&E[1],&E[m+1],cmp);
  scanf("%d",&q);
  for (i=1;i<=q;++i)
  {
    scanf("%d%d",&x,&y);
    Add(x,y,i);
    Add(y,x,i);
    Ans[i]=-1;
  }
  memset(father,255,sizeof(father));
  for (i=1;i<=m;++i)
  {
    if (find(E[i].u)!=find(E[i].v))
    {
      //Union
      sum=father[find(E[i].v)]+father[find(E[i].u)];
      if (father[find(E[i].v)]>father[find(E[i].u)])
      {
        //v -> u
        j=find(E[i].v); root=find(E[i].u);
        father[find(E[i].v)]=find(E[i].u);
        father[find(E[i].u)]=sum;
      }
      else
      {
        //u -> v
        j=find(E[i].u); root=find(E[i].v);
        father[find(E[i].u)]=find(E[i].v);
        father[find(E[i].v)]=sum;
      }
      //printf("%d - %d -> %d %d:\n",i,E[i].u,E[i].v,E[i].w);
      //printf("Little Head = %d , Big Head = %d\n",j,root);
      next[last[root]]=j;
      last[root]=last[j];
      for (;j;j=next[j])
      {
        //printf("InChain %d\n",j);
        for (k=head[j];k;k=pre[k])
        {
          //printf("%d %d %d\n",j,d[k],w[k]);
          if (Ans[w[k]]==-1&&find(j)==find(d[k]))
            Ans[w[k]]=E[i].w;
        }
      }
    }
  }
  for (i=1;i<=q;++i)
    printf("%d\n",Ans[i]);
  //while(1);
  return 0;
}
