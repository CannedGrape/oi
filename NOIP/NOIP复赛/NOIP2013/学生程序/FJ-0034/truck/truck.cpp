#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
int maxway[3001][3001];
int best[3001][3001];
int f[10001],n,m,x,y,z,q;
int try1(int origin,int pre,int start,int end)
{
    int great,temp,i;
    if(best[start][end]!=-1)
      return best[start][end];
    if(maxway[start][end]!=-1)
      {great=maxway[start][end];
       for(i=1;i<=n;i++)
         {if(maxway[start][i]>great&&i!=pre&&i!=origin)
             {temp=try1(origin,start,i,end);
              temp=temp>maxway[start][i]?maxway[start][i]:temp;
              if(temp>great)
                great=temp;
             }
         }
      }
    else
      {great=-1;
       for(i=1;i<=n;i++)
         {if(i!=origin&&i!=pre&&maxway[start][i]!=-1)
            {temp=try1(origin,start,i,end);
             temp=temp>maxway[start][i]?maxway[start][i]:temp;
             if(temp>great)
               great=temp;
            }
         }
      }
    best[start][end]=great;
    best[end][start]=great;
    return great;
}
int getfather(int u)
{
    int fa;
    if(f[u]==u)
       return u;
    fa=getfather(f[u]);
    f[u]=fa;
    return f[u];
}
int main()
{
    int i,j,fu,fv,ans;
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      f[i]=i;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
         {maxway[i][j]=-1;
          best[i][j]=-1;
         }
    for(i=1;i<=m;i++)
      {scanf("%d%d%d",&x,&y,&z);
       fu=getfather(x);
       fv=getfather(y);
       if(fu!=fv)
         f[fu]=fv;
       if(z>maxway[x][y])
          {maxway[x][y]=z;
           maxway[y][x]=z;
          }
      }
    scanf("%d",&q);
    for(i=1;i<=q;i++)
      {scanf("%d%d",&x,&y);
       fu=getfather(x);
       fv=getfather(y);
       if(fu!=fv)
          printf("-1\n");
       else
          {ans=try1(x,0,x,y);
           printf("%d\n",ans);
          }
      }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
       
