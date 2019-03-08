#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#define MXN 100010
using namespace std;
int n,h[MXN];
void init()
{
     scanf("%d",&n);
     for (int i=1;i<=n;i++)
       scanf("%d",&h[i]);
}
void solve()
{
     int ans=0;
     int last=0;
     h[0]=0;
     for (int i=1;i<=n;i++)
     {
       if (h[i]<h[i-1])
       {
         ans+=(h[i-1]-h[last]);
         last=i;
       }
     }
     ans+=h[n]-h[last];
     printf("%d",ans);
}
int main ()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    init();
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}
