#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;
int n,m,q,x,y,m,n;
int mubiao[10000][10000];
int z[10000][10000]={};
bool flag[10000][10000]={};
int father[10000];
int dfs(int a,int b,int c,zuixiao)
{
    int i;
    if(b==c)return z[a][b];
    for(i=1;i<=n;i++)
      if(flag[b][i]==1)
        if(zuixiao>dfs(b,i,c,zuixiao))
          zuixiao=dfs(b,i,c,zuixiao);
    return zuixiao;
int getfather(int u)
{
    if(father[u]==u)
      return u;
    else
      return getfather(father[u]);
}
int main
{
      int i,j,dangqian,u,v;
      scanf("%d%d", &n, &m);
      for(i=1;i<=n;i++)
        father[i]=i;
      for(i=1;i<=m;i++)
        {
        scanf("%d%d%d", &x, &y, &dangqian);
        flag[x][y]=true;
        u=getfather(x);
        v=getfather(y);
        if(u!=v)
          {
          father[y]=father[x];
          }
        if(dangqian>z[x][y])
          z[x][y]=dangqian;
        }
      for(i=1;i<=q;i++)
        {
        scanf("%d%d", &m, &n);
        if(father[m]!=father[n])
          cout<<-1;
        else
          for(j=1;j++;j<=n)
            if(flag[m][j]==1)
            shuchu=dfs(m,j,n,z[m][j])
          cout<<shuchu;
        
        }
            
            
            
            
            
            
