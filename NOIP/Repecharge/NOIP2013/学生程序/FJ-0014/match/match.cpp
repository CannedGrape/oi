#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
const int MOD= 99999997;
const int MAXN=100000+5;
int n;
int a[MAXN], b[MAXN];
int id[MAXN];
namespace LISAN
{
    typedef struct
    {
        int value;
        int* pos;
    } TItem;
    TItem tmp[MAXN];
    int count;
    
    inline bool cmp(const TItem &a, const TItem &b)
    {
        return a.value<b.value;
    }
    
    void work()
    {
        std::sort(tmp+1,tmp+count+1,cmp);
        for (int i=1; i<=count; ++i)
        {
            *(tmp[i].pos) = i;
        }
    }
}

void Input()
{
    using namespace LISAN;
    scanf("%d\n", &n);
    count=0;
    for (int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        ++count;
        tmp[count].value=a[i];
        tmp[count].pos=&a[i];
    }
    work();
    count=0;
    for (int i=1; i<=n; ++i)
    {
        scanf("%d", &b[i]);
        ++count;
        tmp[count].value=b[i];
        tmp[count].pos=&b[i];
    }
    work();
    for (int i=1; i<=n; ++i) // a as ref
    {
        id[a[i]]=i;   
    }
    for (int i=1; i<=n; ++i)
        b[i]=id[b[i]];
}

int dest[MAXN], now[MAXN], disFrom[MAXN];
int scount, cost[MAXN], ccount;
bool vst[MAXN];

void Solve()
{
    scount=0;
    ccount=0;
    for (int i=1; i<=n; ++i)
    {
        if (b[i]!=i)
        {
            ++scount;
            now[scount]=i;
            dest[i]=b[i];
            disFrom[i]=abs(i-b[i]);
        }
    }
    int total;
    memset(vst,false,sizeof(vst));
    for (int i=1; i<=scount; ++i)
        if (!vst[now[i]])
        {
            ++ccount;
            total=0;
            cost[ccount]=0;
            for (int p=now[i]; !vst[p]; p=dest[p])
            {
                ++total;
                vst[p]=true;
                cost[ccount]=(cost[ccount]+disFrom[p])%MOD;
            }
            cost[ccount]-=total-1;
            while (cost[ccount]<0)
                cost[ccount]+=MOD;
            cost[ccount]%=MOD;
        }
        
    int ans=0;
    for (int i=1; i<=ccount; ++i)
        ans=(ans+cost[i])%MOD;
    printf("%d\n", ans);
}

int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    Input();
    Solve();
    return 0;
}
