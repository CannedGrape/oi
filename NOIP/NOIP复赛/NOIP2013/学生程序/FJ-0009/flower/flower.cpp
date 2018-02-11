#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#define MXN 1010
using namespace std;
/*
i=2..n
f[i][0]=f[i][1]=1;
j=1..i-1
f[i][0]=max(f[i][0],f[j][1]+1) |h[j]>h[i],j<i
f[i][1]=max(f[i][1],f[j][0]+1) |h[j]<h[i],j<i

f[1][0]=f[1][1]=1;
*/
int n,h[MXN];
void init()
{
     scanf("%d",&n);
     for (int i=1;i<=n;i++)
       scanf("%d",&h[i]);
}
int f[MXN][2];
void solve()
{
     int ans=1;
     f[1][0]=f[1][1]=1;
     for (int i=2;i<=n;i++)
     {
       f[i][0]=f[i][1]=1;
       for (int j=1;j<i;j++)
       {
         if (h[j]>h[i]&&j<i)  f[i][0]=max(f[i][0],f[j][1]+1);
         if (h[j]<h[i]&&j<i)  f[i][1]=max(f[i][1],f[j][0]+1);
       }
       ans=max(ans,max(f[i][0],f[i][1]));
     }
     printf("%d",ans);
}  
int main ()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    init();
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}
