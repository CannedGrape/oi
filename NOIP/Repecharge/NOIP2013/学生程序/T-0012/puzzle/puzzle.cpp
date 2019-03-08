#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
using namespace std;
int ii,i1,i2,j3,j2,k1,k2
,x,y,i,j,k,mbx,mby,n,m,q,p[33][33],
g[31][31][31][31],gg[31][31][31][31]
,cc[1000000],c[100000]
,l[100000],dx[5]={0,-1,0,0,1},dy[5]={0,0,-1,1,0};
bool pp[33][33],pd;
int main()
{freopen("puzzle.in","r",stdin);
 freopen("puzzle.out","w",stdout);
 scanf("%d%d%d",&n,&m,&q);
 for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
       scanf("%d",&p[i][j]);
 for(ii=1;ii<=q;ii++)
    {scanf("%d%d%d%d%d%d",&k1,&k2,&i2,&j2,&i1,&j3);
     l[0]=0;pd=0;k=0;
     l[++l[0]]=i2*100+j2;pp[i2][j2]=1;
     for(i=1;i<=l[0]&&pd==0;i++)
        {for(j=1;j<=4&&pd==0;j++)
            {x=l[i]/100+dx[j];y=l[i]%100+dy[j];
             if(p[x][y]==1&&pp[x][y]==0)
               {pp[x][y]=1;
               l[++l[0]]=x*100+y;
               c[l[0]]=c[i]+1;
               if(x==i1&&y==j3)
                 {k++;if(k==2)pd=1;else gg[i2][j2][i1][j3]+=c[l[0]];g[i2][j2][i1][j3]+=c[l[0]];}
               }
             }
        }
     for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
           pp[i][j]=0;
     l[0]=0;pd=0;k=0;cc[1]=gg[k1][k2][i2][j2];
     l[++l[0]]=i2*100+j2;
     for(i=1;i<=l[0]&&pd==0;i++)
        {for(j=1;j<=4&&pd==0;j++)
            {x=l[i]/100+dx[j];y=l[i]%100+dy[j];
             if(p[x][y]==1&&pp[x][y]==0)
               {pp[x][y]=1;
               l[++l[0]]=x*100+y;
               c[l[0]]=c[i]+1;
               cc[l[0]]=min(cc[i],gg[k1][k2][x][y]);
               if(x==i1&&y==j3)
                 {k++;if(k==2)pd=1;else gg[i2][j2][i1][j3]+=c[l[0]];g[i2][j2][i1][j3]+=c[l[0]];}
               }
             }
        }
    if(k!=2)cout<<-1<<endl;
    else
    printf("%d %d\n",g[i2][j2][i1][j3],c[l[0]]);
    }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
