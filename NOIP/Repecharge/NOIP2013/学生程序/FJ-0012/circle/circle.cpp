#include <iostream>
#include <cstdio>
#include <functional>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

ll n,m,k,x;

void Init()
{
    cin >> n >> m >> k >> x;
}

ll mul(ll nb,ll ci)
{
    ll ans = 1;
    while (ci)
    {
        if (ci % 2 == 1) ans = (ans * nb) % n;
        nb = (nb * nb) % n;
        ci /= 2;
    }
    return ans % n;
}

void Work()
{
    ll t = (m * mul(10,k)) % n;
    t = ((x % n) + t) % n;
    cout << t << endl;
}

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    Init();
    Work();
    return 0;
}
