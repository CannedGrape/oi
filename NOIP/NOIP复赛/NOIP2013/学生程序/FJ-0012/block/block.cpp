#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100000 + 10;
int n;
int a[N],b[N],ans;

int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    for (int i = 1; i <= n + 1; i++)
        b[i] = a[i] - a[i - 1];
    for (int i = 1; i <= n + 1; i++)
        if (b[i] > 0) ans += b[i];
    cout << ans << endl;
    return 0;
}
