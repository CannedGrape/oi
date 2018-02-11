#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#define N 2147483647
using namespace std;
bool map[31][31]={},a[31][31]={};
int m,n,q,ex,ey,sx,sy,tx,ty,minn=N,
    zx[4]={1,-1,0,0},
    zy[4]={0,0,1,-1},
    gsc[900][3]={};
bool pan(int x,int y,int j)
{   for(int i=1;i<=j;i++)
      if(gsc[i][1]==x&&gsc[i][2]==y)return false;
    return true;
}
int gs(int x,int y,int xx,int yy,int fx,int fy)
{   bool sign=true;
    map[fx][fy]=0;
    int i=1,j,t=1;
    gsc[1][1]=x;
    gsc[1][2]=y;
    gsc[1][0]=0;
    while(sign)
      {sign=false;
       for(j=0;j<=3;j++)
          if((gsc[t][1]+zx[j]<=n)&&(gsc[t][1]+zx[j]>=1)&&(gsc[t][2]+zy[j]<=m)&&(gsc[t][2]+zy[j]>=1))
            if(map[gsc[t][1]+zx[j]][gsc[t][2]+zy[j]]==1)
              if(pan(gsc[t][1]+zx[j],gsc[t][2]+zy[j],i))
                {sign=true;
                 i++;
                 gsc[i][1]=gsc[t][1]+zx[j];
                 gsc[i][2]=gsc[t][2]+zy[j];
                 gsc[i][0]=gsc[t][0]+1;
                 if(gsc[i][1]==xx&&gsc[i][2]==yy)return gsc[i][0];
                }
       t++;
      }
    map[fx][fy]=1;
    return -1;
}
void dfs(int x,int y,int kx,int ky,int t)
{   int i,k,ans;
    for(i=0;i<=3;i++)
      {if((x+zx[i]<=n)&&(x+zx[i]>=1)&&(y+zy[i]<=m)&&(y+zy[i]>=1))
        if(a[x+zx[i]][y+zy[i]]==1)
          {k=gs(kx,ky,x+zx[i],y+zy[i],x,y);
           if(k!=-1)
             {a[x+zx[i]][y+zy[i]]=0;
              ans=t+1+k;
              if((x+zx[i]==tx)&&(y+zy[i]==ty))
                 {if(ans<minn)minn=ans;}
              else
                dfs(x+zx[i],y+zy[i],x,y,ans);
              a[x+zx[i]][y+zy[i]]=1;
             }
          }
      }
}
int ss()
{   if(sx==tx&&sy==ty)return 0;
    minn=N;
    a[sx][sy]=0;
    dfs(sx,sy,ex,ey,0);
    a[sx][sy]=1;
    if(minn==N)return -1;
    else return minn;
}
int main()
{   freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    int i,j;
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
         {scanf("%d",&map[i][j]);
          a[i][j]=map[i][j];
         }
    for(i=1;i<=q;i++)
      {scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
       if(a[ex][ey]==0||a[sx][sy]==0||a[tx][ty]==0){printf("-1\n");continue;}
       printf("%d\n",ss());
      }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
