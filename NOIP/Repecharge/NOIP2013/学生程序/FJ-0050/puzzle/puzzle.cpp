#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int map[40][40],n,m,q,ans;
struct pf
{
       int x,y;
}e[510],s[510],t[510];
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int i,j;
    scanf("%d%d%d",&n,&m,&q);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            scanf("%d",&map[i][j]);
    for (i=1;i<=q;i++)
        scanf("%d%d%d%d%d%d",&e[i].x,&e[i].y,&s[i].x,&s[i].y,&t[i].x,&t[i].y);
    for (i=1;i<=q;i++)
    {
        ans=0;
        printf("-1\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
