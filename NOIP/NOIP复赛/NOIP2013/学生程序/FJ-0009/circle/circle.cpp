#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int n,m,k,x;
int ans;
typedef long long ll;
void init()
{
     scanf("%d%d%d%d",&n,&m,&k,&x);
}
void solve()
{
     int t=1;
     for (int i=1;i<=k;i++)
       t=(t*10)%n;
     ans=(int(  ll(t) * (ll(m)%ll(n))  %ll(n)  )+x%n)%n;
     printf("%d",ans);
}
int main ()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    init();
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}
