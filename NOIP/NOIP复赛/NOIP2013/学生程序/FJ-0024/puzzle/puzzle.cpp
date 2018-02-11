#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
       int jx,jy,kx,ky;
}dui[1000010];
int n,m,q,t,xk,yk,qx,qy,zx,zy;
int map[31][31];
int fk[31][31];
int f[31][31][31][31];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int x,int y)
{
     int k,nx,ny;
     for(k=0;k<4;k++)
     {
         nx=x+dx[k];ny=y+dy[k];
         if(nx<1 || ny<1 || nx>n || ny>m || map[nx][ny]==0 || fk[nx][ny]!=0)  continue;
         fk[nx][ny]=t;dfs(nx,ny);  
     }
}
void init()
{
     int i,j;
     scanf("%d%d%d",&n,&m,&q);
     for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  scanf("%d",&map[i][j]);
     for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  if(map[i][j]==1 && !fk[i][j])  {t++;fk[i][j]=t;dfs(i,j);}
}
int bfs()
{
     memset(f,-1,sizeof(f));
     int tou=1,wei=1,k,nx,ny,kgx,kgy,qix,qiy,a,b;
     f[qx][qy][xk][yk]=0;
     dui[1].jx=qx;dui[1].jy=qy;dui[1].kx=xk;dui[1].ky=yk;
     while(tou<=wei)
     {
          kgx=dui[tou].kx;kgy=dui[tou].ky;
          qix=dui[tou].jx;qiy=dui[tou].jy;
          tou++;
          for(k=0;k<4;k++)
          {
              nx=kgx+dx[k];ny=kgy+dy[k];
              if(nx<1 || ny<1 || nx>n || ny>m || map[nx][ny]==0)  continue;
              a=qix;b=qiy;
              if(a==nx && b==ny)
              {
                  a=kgx;b=kgy;
              }
              if(f[a][b][nx][ny]==-1)
              {
                  wei++;dui[wei].jx=a;dui[wei].jy=b;dui[wei].kx=nx;dui[wei].ky=ny;
                  f[a][b][nx][ny]=f[qix][qiy][kgx][kgy]+1;
                  if(a==zx && b==zy)  return f[a][b][nx][ny];
              }
          }
     }
     return -1;
}
void solve()
{
     if(qx==zx && qy==zy)  {printf("0\n");return;}
     if(map[xk][yk]==0 || map[qx][qy]==0 || map[zx][zy]==0)  {printf("-1\n");return;}
     if(fk[qx][qy]!=fk[zx][zy])  {printf("-1\n");return;}
     if(fk[qx][qy]!=fk[xk][yk])  {printf("-1\n");return;}
     printf("%d\n",bfs());
}
void cl()
{
     int i;     
     for(i=1;i<=q;i++)
     {
         scanf("%d%d%d%d%d%d",&xk,&yk,&qx,&qy,&zx,&zy);
         solve();
     }
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    init();
    cl();
    //system("pause");
    return 0;
}
