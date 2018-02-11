#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;

typedef long long lint;

const lint M=99999997;
const int maxN=100000+100;

struct Match
{
    int h,pos;
};

int N;
Match a[maxN], b[maxN];
int p[maxN+1]; // target position +1 of b[i-1];
lint t[maxN+1]; // TreeArr

bool hcmp(const Match& a, const Match& b)
{
    return a.h<b.h;
}

void work()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&a[i].h);
        a[i].pos=i;
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d",&b[i].h);
        b[i].pos=i;
    }

    sort(a,a+N,hcmp);
    sort(b,b+N,hcmp);
    for(int i=0;i<N;i++)
        p[b[i].pos+1] = a[i].pos+1;

    // for(int i=0;i<=N;i++)
    //     printf("%d ",p[i]);
    // puts("");
    lint ans=0;
    memset(t,0,sizeof(t));
    for(int i=N;i>0;i--)
    {
        for(int j=p[i];j;j^=j&-j)
            ans = (ans+t[j])%M;
        for(int j=p[i];j<=N;j+=j&-j)
            t[j]++;
    }
    printf("%lld\n",ans);
}

int main()
{
    freopen("match.in" ,"r",stdin );
    freopen("match.out","w",stdout);
    work();
    return 0;
}
