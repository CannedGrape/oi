#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100000 + 10;
int n,a[N],ans = 1;

int work1()
{
    int ret = 0,fr = 0,i;
    while (true)
    {
        for (i = fr + 1; i < n; i++)
            if (a[i + 1] > a[i])
            {
                ret++;
                fr = i; break;
            }
        if (i >= n - 1) break;
        for (i = fr + 1; i < n; i++)
            if (a[i + 1] < a[i])
            {
                ret++;
                fr = i; break;
            }
        if (i >= n - 1) break;
    }
    return ret + 1;
}

int work2()
{
    int ret = 0,fr = 0,i;
    while (true)
    {
        for (i = fr + 1; i < n; i++)
            if (a[i + 1] < a[i])
            {
                ret++;
                fr = i; break;
            }
        if (i >= n - 1) break;
        for (i = fr + 1; i < n; i++)
            if (a[i + 1] > a[i])
            {
                ret++;
                fr = i; break;
            }
        if (i >= n - 1) break;
    }
    return ret + 1;
}

int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    
    ans = max(work1(),work2());
    cout << ans << endl;
    
    return 0;
}
