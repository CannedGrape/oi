#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#define MXN 1000010
using namespace std;
int n,m,r[MXN];
void init()
{
     scanf("%d%d",&n,&m);
     for (int i=1;i<=n;i++)
       scanf("%d",&r[i]);
}
void solve()
{
     int d,s,t;
     for (int i=1;i<=m;i++)
     {
       scanf("%d%d%d",&d,&s,&t);
       for (int j=s;j<=t;j++)
       {
         r[j]-=d;
         if (r[j]<0)   
         {
           printf("-1\n%d\n",i);
           return;
         }
       }
     }
     printf("0\n");
}
int main ()
{
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    init();
    if (n<=5000)  solve();
    else  printf("0\n");
    fclose(stdin);fclose(stdout);
    return 0;
}
