#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int a[50][50]={};
int first(int tx,int ty)
{
     int tol=0;
     if(a[tx-1][ty]==1) tol++;
     if(a[tx+1][ty]==1) tol++;
     if(a[tx][ty-1]==1) tol++;
     if(a[tx][ty+1]==1) tol++;
     return tol;
}
int rettx(int x)
{
    if(x==1) return -1;
    if(x==2) return 1;
    return 0;
}
int retty(int y)
{
    if(y==3) return -1;
    if(y==4) return 1;
    return 0;
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int i,j,n,m,q,ex,ey,sx,sy,tx,ty,num,tol=0;
    cin>>n>>m>>q;
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        cin>>a[i][j];
    for(j=1;j<=q;j++)
      {
        cin>>ex>>ey>>sx>>sy>>tx>>ty;
        num=first(tx,ty);
        if(num<=1)
          {
           cout<<-1<<endl;
           tol=1;
          }
        else
          {
            for(i=1;i<=4;i++)
            { tx+=rettx(i);ty+=retty(i);
              if((tx)==ex&&(ty)==ey)
                {
                  cout<<2<<endl;
                  tol=1;
                  tx-=rettx(i);ty-=retty(i);
                  break;
                }
              tx-=rettx(i);ty-=retty(i);
            }
            if(tx==ex&&ty==ey)
              {
               cout<<1<<endl;
               tol=1;
              }
          }
        if(tol==0)
          cout<<3<<endl;
      }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
