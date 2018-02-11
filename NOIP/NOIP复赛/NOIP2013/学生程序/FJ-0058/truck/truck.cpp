#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define P 101000

using namespace std;

int n,m,q,dis[1010][1010],pos[P],sta[P],end[P],ans[P];
int m0,head[P],pre[P],tar[P],val[P],stack[P],top,vis[1010],sour;

void addl(int a,int b,int c)
{
     ++m0;pre[m0] = head[a];head[a] = m0;val[m0] = c;tar[m0] = b;
     ++m0;pre[m0] = head[b];head[b] = m0;val[m0] = c;tar[m0] = a;
}

void dfs(int k)
{
     int i,j;
     vis[k] = 1;
     for(i = head[k];i;i = pre[i])
     {
           if(!vis[tar[i]])
           {
              if(top == 0) stack[++top] = val[i];
              else 
              {
                   ++top;stack[top] = min(val[i],stack[top - 1]);
              }
              dis[sour][tar[i]] = max(dis[sour][tar[i]],stack[top]);
              dfs(tar[i]);
              --top;
           }
     }
     vis[k] = 0;
}

void qort(int l,int r)
{
     int i = l,j = r,mid = sta[(l + r) >> 1];
     while(i <= j)
     {
             while(sta[i] < mid) ++i;
             while(sta[j] > mid) --j;
             if(i <= j)
             {
                  swap(sta[i],sta[j]);
                  swap(end[i],end[j]);
                  swap(pos[i],pos[j]);
                  ++i;--j;
             }
     }
     if(i < r) qort(i,r);
     if(l < j) qort(l,j);
}

int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int i,j,a,b,c,x;
    scanf("%d%d",&n,&m);
    for(i = 1;i <= m;i++)
    {
          scanf("%d%d%d",&a,&b,&c);
          addl(a,b,c);
    }
    scanf("%d",&q);
    for(i = 1;i <= q;i++)
    {
          scanf("%d%d",&sta[i],&end[i]);
          pos[i] = i;
    }
    qort(1,q);
    for(i = 1;i <= n;i++) 
          for(j = 1;j <= n;j++) dis[i][j] = -1;
    x = 0;
    for(i = 1;i <= q;i++)
    {
          if(x != sta[i])
          {
               x = sta[i];
               sour = x;
               top = 0;
               dfs(x);
          }
          ans[pos[i]] = dis[sta[i]][end[i]];
    }
    for(i = 1;i <= q;i++) printf("%d\n",ans[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
