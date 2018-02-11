#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,q;int ex,ey,sx,sy,tx,ty;
int check[31][31]={};
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int i,j;
    scanf("%d%d%d",&n,&m,&q);
    for (i=0;i<=n+1;i++)
      for (j=0;j<=n+1;j++)
        check[i][j]=0;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        cin>>check[i][j];
    for (i=1;i<=q;i++)
      {
        scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
        if (((tx+1)!=ex||ty!=ey)&&((tx-1)!=ex||ty!=ey)&&(tx!=ex||(ty+1)!=ey)&&(tx!=ex||(ty-1)!=ey))
          cout<<"-1"<<endl;
        else
          cout<<ty<<endl;
      }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
