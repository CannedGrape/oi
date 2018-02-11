#include <iostream>
#include <cstdio>
#include <functional>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int mod = 99999997;
const int N = 100000 + 10;
int n,bl[N],ans,sum[10 * N];
struct Node
{
    int v,pos;
}a[N],b[N];

bool cmp(Node a1,Node a2)
{
    return a1.v < a2.v;
}

void Init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        {scanf("%d",&a[i].v); a[i].pos = i;}
    for (int i = 1; i <= n; i++)
        {scanf("%d",&b[i].v); b[i].pos = i;}
    sort(a + 1,a + n + 1,cmp);
    sort(b + 1,b + n + 1,cmp);
    for (int i = 1; i <= n; i++)
        bl[a[i].pos] = b[i].pos;
}

int Find(int p,int l,int r,int ll,int rr)
{
    if (l > rr || r < ll) return 0;
    if (l >= ll && r <= rr)
    {
        return sum[p];
    }
    int mid = (l + r) / 2;
    return Find(p * 2,l,mid,ll,rr) + Find(p * 2 + 1,mid + 1,r,ll,rr);
}

void Ins(int p,int l,int r,int pp)
{
    if (l > pp || r < pp) return;
    if (l == r)
    {
        sum[p]++;
        return;
    }
    int mid = (l + r) / 2;
    Ins(p * 2,l,mid,pp); Ins(p * 2 + 1,mid + 1,r,pp);
    sum[p] = sum[p * 2] + sum[p * 2 + 1];
}

void work()
{
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + Find(1,1,n,bl[i],n)) % mod;
        Ins(1,1,n,bl[i]);
    }
    cout << ans << endl;
}

int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    Init();
    work();
    return 0;
}
