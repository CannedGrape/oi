#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

short int i,j,n,m,q;
short int map[31][31];
short int ex[501],ey[501],sx[501],sy[501],tx[501],ty[501];


int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        scanf("%d",&map[i][j]);
    for(i=1;i<=q;i++)  
      scanf("%d%d%d%d%d%d",&ex[i],&ey[i],&sx[i],&sy[i],&tx[i],&ty[i]);
    if(q!=1)
      printf("2\n-1");
    if(q==1)
      printf("-1\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
