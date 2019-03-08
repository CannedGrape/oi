#include<cstdio>
#define maxn 200010
using namespace std;
long long a[maxn];
int n,i,j;
long long ans;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    
    scanf("%d",&n);
    a[0]=0;
    for (int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    ans=0;
    for (int i=1;i<=n;i++)
        if (a[i]>a[i-1])
            ans+=a[i]-a[i-1];
    printf("%lld\n",ans);
    //while (1);
    return 0;
}
