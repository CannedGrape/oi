#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100001;
const int mod = 99999997;
int n,a[maxn],b[maxn];
struct node
{
       int val, id;
}trya[maxn],tryb[maxn];
int paia[maxn],paib[maxn];
bool cmp (node aa, node bb)
{
     return aa.val < bb.val;
}
void input ()
{
     int i;
     scanf ("%d", &n);
     for (i=1; i<=n; i++)
     {
         scanf ("%d", &a[i]);
         trya[i].val=a[i];
         trya[i].id=i;
     }
     for (i=1; i<=n; i++)
     {
         scanf ("%d", &b[i]);
         tryb[i].val=b[i];
         tryb[i].id=i;
     }
     sort (trya+1, trya+n+1, cmp);
     sort (tryb+1, tryb+n+1, cmp);
     for (i=1; i<=n; i++)
     {
         paia[trya[i].id]=i;
         paib[i]=tryb[i].id;
     }
}

void doing ()
{
     int i,j,ans=0;
     for (i=1; i<=n; i++)
     for (j=i+1; j<=n; j++)
         if (paib[paia[i]] > paib[paia[j]])
            ans=(ans+1)%mod;
     cout<<ans;
}

int main ()
{
    freopen ("match.in", "r", stdin);
    freopen ("match.out","w",stdout);
    input ();
    doing ();
    return 0;
}
