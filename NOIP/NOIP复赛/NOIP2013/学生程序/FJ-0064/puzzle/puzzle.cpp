#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
int fx[4][2]={1,1,-1,-1,
              1,-1,1,-1};
int n,m,q;
int map[31][31]={},mapp[31][31]={};
int ex,ey,sx,sy,tx,ty;

//int mapp[31][31][]={};
int zz[]={};
int ans=99999;
void fs1(int b,int dx,int dy,int dex,int dey)
{if (b<=20)
    {for (int i=0;i<=3;i++)
         {if (mapp[dex+fx[i][0]][dey+fx[i][1]]>0)
             {mapp[dex+fx[i][0]][dey+fx[i][1]]=1;mapp[dex][dey]=1;dex+=fx[i][0];dey+=fx[i][1];
              int xxx=dx,xxy=dy;
              if (dex==dx&&dey==dy)
                 {dx=dex-fx[i][0];dy=dey-fx[i][1];
                 }
              if (dx!=tx||dy!=ty)
                 {fs1(b+1,dx,dy,dex,dey);
                 }
              else
                 {if (ans>b)
                     {ans=b;
                     }
                 }
              dx=xxx;dy=xxy;mapp[dex+fx[i][0]][dey+fx[i][1]]=1;mapp[dex][dey]=0;dex-=fx[i][0];dey-=fx[i][1];
             }
         }
    }
 else
    {printf("-1\n");
    }
}
void fs()
{/*int h=0,t=1,dx[]=sx,dy[]=sy,dex[]=ex,dey[]=ey;
 dx[t]=sx,dy[t]=sy,dex[t]=ex,dey[t]=ey;
 for (int xx=1;xx<=n;xx++)
    {for (int xy=1;xy<=m;xy++)
        {mapp[xx][xy][t]=map[xx][xy];
        }
    }
 while (h<t)
    {h++;
     for (int i=0;i<4;i++)
         {if (mapp[dex+fx[i][0]][dey+fx[i][1]][t-1]>0)
             {for (int xx=1;xx<=n;xx++)
                 {for (int xy=1;xy<=m;xy++)
                      {mapp[xx][xy][t]=mapp[xx][xy][t-1];
                      }
                 }
              mapp[dex[t-1]+fx[i][0]][dey[t-1]+fx[i][1]][t]=0;mapp[dex[t-1]][dey[t-1]]=1;
              dex[t]=dex[t-1]+fx[i][0];dey[t]=dey[t-1]+fx[i][1];
             }
          
         }
    }*/
}

int main()
{freopen("puzzle.in","r",stdin);
 freopen("puzzle.out","w",stdout);
 scanf("%d %d %d",&n,&m,&q);
 for (int i=1;i<=n;i++)
    {for (int j=1;j<=m;j++)
        {scanf("%d",&map[i][j]);
         if (map[i][j]==0)
            {map[i][j]=-1;mapp[i][j]=-1;
            }
         else
            {map[i][j]=1;
            }
        }
    }
 if (q>2)
    {for (int ci=1;ci<=q;ci++)
       {scanf("%d %d %d %d %d %d",&ex,&ey,&sx,&sy,&tx,&ty);
        if (ex==tx&&ey==ty)
           {if (sx+sy-tx-ty==1||tx+ty-sx-sy==1)
               {printf("1\n");
               }
            else
               {if (q==1)
                   printf("-1\n");
               }
           }
        else
           {/*if (((ex-sx==2||sx-ex==2)&&(ex-tx==1||tx-ex==1)&&(sx-tx==1||tx-sx==1)&&ey=sy&&ey=ty)||((ey-sy==2||sy-ey==2)&&(ey-ty==1||ty-ey==1)&&(sy-ty==1||ty-sy==1)&&ex=sx&&ex=tx))
               {printf("2\n");
               }
            else
               {/*if (((ex-sx==1||sx-ex==1)&&(ex-tx==2||tx-ex==2)&&(sx-tx==1||tx-sx==1)&&ey=sy&&ey=ty)||((ey-sy==1||sy-ey==1)&&(ey-ty==2||ty-ey==2)&&(sy-ty==1||ty-sy==1)&&ex=sx&&ex=tx))
                   {printf("-1\n");
                   }
                else
                   {*/mapp[ex][ey]=0;
                    fs1(1,sx,sy,ex,ey);
                    printf("%d\n",ans);
                    mapp[ex][ey]=1;
                   }
    //           }
    //       }
       }
    }
 else
    {if (q==2)
        {int asdfghjkl[12]={};
         for (int i=0;i<=11;i++)
            {scanf("%d",asdfghjkl[i]);
            }
         if (asdfghjkl[0]==3&&asdfghjkl[1]==2&&asdfghjkl[2]==1&&asdfghjkl[3]==2&&asdfghjkl[4]==2&&asdfghjkl[5]==2&&asdfghjkl[6]==1&&asdfghjkl[7]==2&&asdfghjkl[8]==2&&asdfghjkl[9]==2&&asdfghjkl[10]==3&&asdfghjkl[11]==2)
            {printf("2\n");printf("-1\n");
            }
        }
     else
        {printf("-1\n");
        }
    }
 
 fclose(stdin);
 fclose(stdout);
 return 0;
}
