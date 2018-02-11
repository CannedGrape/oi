#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define N 40
#define M 40
using namespace std;
struct node
{
       int kx,ky,xx,yy;
};
queue<node>w;
bool flag[N][M],pd[910][910];
int cx[4]={0,0,-1,1};
int cy[4]={1,-1,0,0};
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int n,m,i,j,q,ex,ey,sx,sy,tx,ty,ans,a,b;
    scanf("%d%d%d",&n,&m,&q);
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        scanf("%d",&flag[i][j]);
    node vv,v2;
    while (q--)
      {scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
       ans=0;
       memset(pd,0,sizeof(pd));
       vv.kx=ex;
       vv.ky=ey;
       vv.xx=sx;
       vv.yy=sy;
       a=(ex-1)*m+ey;
       b=(sx-1)*m+sy;
       pd[a][b]=1;
       w.push(vv);
       flag[0][0]=1;
       while (!w.empty() && flag[0][0])
         {ans++;
          vv=w.front();
          w.pop();
          for (i=0;i<4 && flag[0][0];i++)
            {v2.kx=vv.kx+cx[i];
             v2.ky=vv.ky+cy[i];
             if (v2.kx>=1 && v2.kx<=n && v2.ky>=1 && v2.ky<=m)
               {if (v2.kx==vv.xx && v2.ky==vv.yy)
                  {v2.xx=vv.kx;
                   v2.yy=vv.ky;
                  }
                else
                  {v2.xx=vv.xx;
                   v2.yy=vv.yy;
                  }
                a=(v2.kx-1)*m+v2.ky;
                b=(v2.xx-1)*m+v2.yy;  
                if (flag[v2.kx][v2.ky] && !pd[a][b])
                  {pd[a][b]=1;  
                   if (v2.xx==tx && v2.yy==ty) 
                     {printf("%d\n",ans);  
                      flag[0][0]=0;
                     }
                   w.push(v2);
                }
               }
            }
         }
       if (flag[0][0]) printf("-1\n");  
      }    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
