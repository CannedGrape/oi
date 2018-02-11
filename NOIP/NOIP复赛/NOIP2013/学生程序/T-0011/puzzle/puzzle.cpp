#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,p,f[31][31][5],x,x2,x3,y,y2,y3,a[31][31],dx[5]={0,1,0,-1,0},dy[5]={0,0,1,0,-1},g[31][31],
hx[901],hy[901],h;
bool q[31][31][5];
inline int cdx(int b,int c,int d,int e,int _,int __)
{
       int i,j;
       for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
           g[i][j]=0;
       g[b][c]=1;
       g[d][e]=-1;
       h=1;
       hx[1]=b;
       hy[1]=c;
       for(i=1;i<=h;i++)
         for(j=1;j<=4;j++)
           if(hx[i]+dx[j]>0 && hx[i]+dx[j]<=n && hy[i]+dy[j]>0 && hy[i]+dy[j]<=m &&
           a[hx[i]+dx[j]][hy[i]+dy[j]]==1 && g[hx[i]+dx[j]][hy[i]+dy[j]]==0)
             {
              g[hx[i]+dx[j]][hy[i]+dy[j]]=g[hx[i]][hy[i]]+1;
              hx[++h]=hx[i]+dx[j];
              hy[h]=hy[i]+dy[j];
              if(hx[h]==_ && hy[h]==__)
                return g[_][__];
             }
       return 100000000;
}
inline int ss(int i,int j,int k)
{
       if(f[i][j][k]>0)
         return f[i][j][k];
       if(i==x3 && j==y3)
         return 0;
       int t,u;
       f[i][j][k]=100000000;
       q[i][j][k]=1;
       for(t=1;t<=4;t++)
         if(i+dx[t]>0 && i+dx[t]<=n && j+dy[t]>0 && j+dy[t]<=m && q[i+dx[t]][j+dy[t]][(t+1)%4+1]==0
         && a[i+dx[t]][j+dy[t]]==1)
           {
            u=ss(i+dx[t],j+dy[t],(t+1)%4+1)+cdx(i+dx[t],j+dy[t],i,j,i+dx[k],j+dy[k]);
            if(u<f[i][j][k])
              f[i][j][k]=u;
           }
       q[i][j][k]=0;
       return f[i][j][k];
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int i,j,k,l;
    scanf("%d%d%d",&n,&m,&p);
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
    while(p>0)
      {
       p--;
       for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
           for(k=1;k<=4;k++)
             f[i][j][k]=0;
       scanf("%d%d%d%d%d%d",&x,&y,&x2,&y2,&x3,&y3);
       for(j=1,i=100000000;j<=4;j++)
         if(x2+dx[j]>0 && x2+dx[j]<=n && y2+dy[j]>0 && y2+dy[j]<=m && a[x2+dx[j]][y2+dy[j]]==1)
           i=min(ss(x2+dx[j],y2+dy[j],(j+1)%4+1)+cdx(x2+dx[j],y2+dy[j],x2,y2,x,y),i);
       printf("%d\n",i>=100000000?-1:i);
      }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
