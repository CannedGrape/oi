#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;
int n,m,k,x;
long long ans,dishu;
void input ()
{
     scanf ("%d %d %d %d", &n, &m, &k, &x);
}
long long domi (int xx)
{
    long long res;
    if (xx==1) return dishu;
    
    res=(domi(xx/2)*domi(xx/2))%n;
    if (xx%2) res=(res*dishu)%n;
    return res;
}
void doing ()
{
     dishu=10%n;
     ans=( x%n + m*domi(k) ) % n;
}
void output ()
{
     cout<<ans;
}
int main ()
{
    freopen ("circle.in", "r", stdin);
    freopen ("circle.out","w",stdout);
    input ();
    doing ();
    output ();
    return 0;
}
