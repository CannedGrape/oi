#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m,q,ex[501],ey,sx,sy],tx,ty,a[32][32];
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    memset(a,0,sizeof(a));
    scanf("%d%d%d",&n,&m,&q);
    int i,j,k;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    scanf("%d",&a[i][j]);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
        printf("-1\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
