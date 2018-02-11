#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
const int MAXN=100000+5;
int n, h[MAXN];
int maxh=-1;

inline int Max(const int a, const int b)
{
    return (a>b)?a:b;
}

/*int work1()
{
    int ans=0;
    for (int i=maxh; i>=1; --i)
    {
        for (int j=1; j<=n; ++j)
            if ((j==1 && h[j]>=i) || (j>1 && h[j-1]<i && h[j]>=i))
                ++ans;
    }
    return ans;
}*/

int work2()
{
    int ans=0, top=0;
    for (int i=1; i<=n; ++i)
    {
        if (h[i]>top)
            top=h[i];
        else if (h[i]<top)
        {
            ans+=top-h[i];
            top=h[i];
        }
    }
    ans+=top;
    return ans;
}

int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d", &h[i]);
        maxh=Max(maxh,h[i]);
    }
    int ans2=work2();
    printf("%d\n", ans2);  
    return 0;
}
