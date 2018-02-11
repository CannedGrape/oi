#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;


  int queuex1[10000];
  int queuey1[10000];
  int queuex2[10000];
  int queuey2[10000];
  int queuestep[10000];
  int map[50][50];
  int ex,ey,sx,sy,tx,ty,n,m,q;
  
  void bfs()
  {
       int x1,x2,y1,y2,head,tail,i,t;
       
       head=1;
       tail=1;
       queuex1[1]=ex;
       queuey1[1]=ey;
       queuex2[1]=sx;
       queuey2[1]=sy;
       queuestep[1]=0;
       while (head<=tail)
       {
             x1=queuex1[head];
             y1=queuey1[head];
             x2=queuex2[head];
             y2=queuey2[head];
             if (map[x1+1][y1]==1)
             {
                                  tail++;
                                  queuex1[tail]=x1+1;
                                  queuey1[tail]=y1;
                                  queuestep[tail]=queuestep[head]+1;
                                  if (queuex2[head]==x1+1 && queuey2[head]==y1)
                                  {
                                      queuex2[tail]=x1;
                                      queuey2[tail]=y1;
                                      if (queuex2[tail]==tx && queuey2[tail]==ty)
                                      {
                                                            printf("%d\n",queuestep[tail]);
                                                            return;
                                      }                    
                                  }
                                  else
                                  {
                                      queuex2[tail]=x2;
                                      queuey2[tail]=y2;
                                  }
                                  for (i=1;i<tail;i++)
                                  {
                                      if (queuex1[i]==queuex1[tail] && queuey1[i]==queuey1[tail] && queuex2[i]==queuex2[tail] && queuey2[i]==queuey2[tail])
                                      {
                                                                    tail--;
                                                                    break;
                                      }
                                  }
             }
             if (map[x1-1][y1]==1)
             {
                                  tail++;
                                  queuex1[tail]=x1-1;
                                  queuey1[tail]=y1;
                                  queuestep[tail]=queuestep[head]+1;
                                  if (queuex2[head]==x1-1 && queuey2[head]==y1)
                                  {
                                      queuex2[tail]=x1;
                                      queuey2[tail]=y1;       
                                      if (queuex2[tail]==tx && queuey2[tail]==ty)
                                      {
                                                            printf("%d\n",queuestep[tail]);
                                                            return;
                                      }      
                                  }
                                  else
                                  {
                                      queuex2[tail]=x2;
                                      queuey2[tail]=y2;
                                  }
                                  for (i=1;i<tail;i++)
                                  {
                                      if (queuex1[i]==queuex1[tail] && queuey1[i]==queuey1[tail] && queuex2[i]==queuex2[tail] && queuey2[i]==queuey2[tail])
                                      {
                                                                    tail--;
                                                                    break;
                                      }
                                  }
             }
             if (map[x1][y1+1]==1)
             {
                                  tail++;
                                  queuex1[tail]=x1;
                                  queuey1[tail]=y1+1;
                                  queuestep[tail]=queuestep[head]+1;
                                  if (queuex2[head]==x1 && queuey2[head]==y1+1)
                                  {
                                      queuex2[tail]=x1;
                                      queuey2[tail]=y1;
                                      if (queuex2[tail]==tx && queuey2[tail]==ty)
                                      {
                                                            printf("%d\n",queuestep[tail]);
                                                            return;
                                      }        
                                  }
                                  else
                                  {
                                      queuex2[tail]=x2;
                                      queuey2[tail]=y2;
                                  }
                                  for (i=1;i<tail;i++)
                                  {
                                      if (queuex1[i]==queuex1[tail] && queuey1[i]==queuey1[tail] && queuex2[i]==queuex2[tail] && queuey2[i]==queuey2[tail])
                                      {
                                                                    tail--;
                                                                    break;
                                      }
                                  }
             }
             if (map[x1][y1-1]==1)
             {
                                  tail++;
                                  queuex1[tail]=x1;
                                  queuey1[tail]=y1-1;
                                  queuestep[tail]=queuestep[head]+1;
                                  if (queuex2[head]==x1 && queuey2[head]==y1-1)
                                  {
                                      queuex2[tail]=x1;
                                      queuey2[tail]=y1;      
                                      if (queuex2[tail]==tx && queuey2[tail]==ty)
                                      {
                                                            printf("%d\n",queuestep[tail]);
                                                            return;
                                      }
                                  }
                                  else
                                  {
                                      queuex2[tail]=x2;
                                      queuey2[tail]=y2;
                                  }
                                  for (i=1;i<tail;i++)
                                  {
                                      if (queuex1[i]==queuex1[tail] && queuey1[i]==queuey1[tail] && queuex2[i]==queuex2[tail] && queuey2[i]==queuey2[tail])
                                      {
                                                                    tail--;
                                                                    break;
                                      }
                                  }
             }
             head++;
       }
       printf("-1\n");
  }

int main()
{
    int i,j;
    
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d %d %d",&n,&m,&q);
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    for (i=1;i<=q;i++)
    {
        scanf("%d %d %d %d %d %d",&ex,&ey,&sx,&sy,&tx,&ty);
        bfs();
    }
    return 0;
}
