#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,q;
int sx,sy,ex,ey,tx,ty;
int dx[5]={0,-1,0,1,0};
int dy[5]={0,0,1,0,-1};
bool map[35][35]={};
int dis(int sa,int sb,int ea,int eb,int ga,int gb)
{
    int x,y,nx,ny;
    queue<int> xx,yy;
    bool map2[35][35]={};
    int d[35][35]={};
    memset(d,0,sizeof(d));
    if(sa==ea && sb==eb) return 0;
    map2[ga][gb]=map2[sa][sb]=1;
    xx.push(sa);
    yy.push(sb);
    do
      {x=xx.front();
       y=yy.front();
       for(int i=1;i<=4;++i)
         {nx=x+dx[i];ny=y+dy[i];
          if( !map2[nx][ny] && map[nx][ny] )
            {map2[nx][ny]=1;
             d[nx][ny]=d[x][y]+1;
             xx.push(nx);
             yy.push(ny);
             if(nx==ea && ny==eb)
               {
                return d[nx][ny];
               }
            }
         }
       xx.pop();
       yy.pop();
      }while( !xx.empty()  );
    return -1;
}
void work()
{
     bool map2[35][35]={};
     int dd[35][35]={};
     int x,y,nx,ny,r,exx,eyy;
     int ans;
     queue<int> xx,yy,eex,eey;
     map2[sx][sy]=1;
     xx.push(sx);
     yy.push(sy);
     eex.push(ex);
     eey.push(ey);
     ans=200000000;
     do
       {
        x=xx.front();
        y=yy.front();
        exx=eex.front();
        eyy=eey.front();
        for(int i=1;i<=4;++i)
          {nx=x+dx[i];ny=y+dy[i];
           r=dis(exx,eyy,nx,ny,x,y);
           if( !map2[nx][ny] && map[nx][ny] && r>-1 )
            {map2[nx][ny]=1;
             dd[nx][ny]=dd[x][y]+r+1;
             
             if(nx==tx && ny==ty)
               {
                if(dd[nx][ny]<ans) ans=dd[nx][ny] ;
               }
             else
               {xx.push(nx);
                yy.push(ny);
                eex.push(x);
                eey.push(y);
               }
            }
         }
       xx.pop();
       yy.pop();
       eex.pop();
       eey.pop();
       }while( !xx.empty() );
     if(ans==200000000) printf("-1\n");
     else printf("%d\n",ans);
     return ;
}
void input()
{
     scanf("%d %d %d",&n,&m,&q);
     for(int i=1;i<=n;++i)
       for(int j=1;j<=m;++j)
         scanf("%d",&map[i][j]); 
     for(int i=1;i<=q;++i)
       {
        scanf("%d %d %d %d %d %d",&ex,&ey,&sx,&sy,&tx,&ty);
        work();
       }
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    input();
    fclose(stdin);
    fclose(stdout);
return 0;
}
