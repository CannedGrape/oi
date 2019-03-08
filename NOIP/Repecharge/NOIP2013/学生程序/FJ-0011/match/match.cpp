/* match.cpp NOIP 2013 day1.B
   By Sweetdumplings @ FZYZ / Fudan University
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
#define MAXN 100002
#define MOD 99999997
struct SortType
{
    int a,b;
}d[MAXN];
int N;
bool Used[MAXN];
bool cmp(SortType a, SortType b)
{
    return (a.a!=b.a)?a.a<b.a:a.b<b.b;
}
int B1[MAXN],B2[MAXN];
bool Mark[MAXN];
int Search(int now)
{
    if (Mark[now]) return 0;
    Mark[now]=1;
    return Search(B2[now])+1;
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&N);
    for (int i=1;i<=N;++i)
    {
        scanf("%d",&d[i].a);
    }
    for (int i=1;i<=N;++i)
    {
        scanf("%d",&d[i].b);
    }
    sort(d+1,d+N+1,cmp);
    
    for (int i=1;i<=N;++i)
    {
        B1[i]=d[i].b;
    }
    std::sort(B1+1,B1+N+1);
    for (int i=1;i<=N;++i)
    {
        int L=1,R=N;
        while (L<R) 
        {
            int mid=(L+R)>>1;
            if (B1[mid]<d[i].b) L=mid+1;
            else R=mid;
        }
        B2[i]=L;
    }
    int Ans=0;
    for (int i=1;i<=N;++i)
    {
        if (B2[i]!=i)if (!Mark[i]) Ans+=Search(i)-1;
    }
    printf("%d\n",Ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
