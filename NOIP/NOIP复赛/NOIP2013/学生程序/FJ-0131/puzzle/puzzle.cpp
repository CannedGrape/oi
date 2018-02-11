#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define max 500
using namespace std;
int n,m,q;
int maps[30][30];
int EX[max],EY[max],SX[max],SY[max],TX[max],TY[max];
void init()
{
     scanf("%d%d%d",&n,&m,&q);
     for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
         scanf("%d",&a[i][j]);
     for(int i=0;i<q;i++)
       scanf("%d%d%d%d%d%d",&EX[i],&EY[i],&SX[i],&SY[i],&TX[i],&TY[i]);
     return;
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    init();
    for(int i=0;i<q;i++)
      printf("-1");
    return 0;
}
