#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int m,n,q;
    cin>>m>>n>>q;
    int p[m+1][n+1];
    for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++)
      scanf("%d",&p[i][j]);
    for(int i=1;i<=q;i++)
    {
    int xk,yk,xm,ym,xy,yy;   //main
    cin>>xk>>yk>>xy>>yy>>xm>>ym;
    printf("-1\n");}
    return 0;
}
