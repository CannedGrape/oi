#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 100010;
const int inf = 9999999;
int h[maxn],n,ans;
void input ()
{
     int i;
     scanf ("%d", &n);
     for (i=1; i<=n; i++) scanf ("%d", &h[i]);
}
void doing (int now, int kind, int last, int res)
{
    if (now==n+1)
    {
       if (res>ans) ans=res;
       return;
    }
    if (kind==0)
    {
       if ((res+1)%2==0 && h[now]>last) doing (now+1, kind, h[now], res+1);
       if ((res+1)%2==1 && h[now]<last) doing (now+1, kind, h[now], res+1);
    } 
    else
    {
       if ((res+1)%2==0 && h[now]<last) doing (now+1, kind, h[now], res+1);
       if ((res+1)%2==1 && h[now]>last) doing (now+1, kind, h[now], res+1);
    }
    doing (now+1, kind, last, res);
}
void work ()
{
     doing(1, 0, inf, 0);
     doing(1, 1, 0, 0);
}
int main ()
{
    freopen ("flower.in", "r", stdin);
    freopen ("flower.out","w",stdout);
    input ();
    work ();
    cout<<ans;
    return 0;
}
