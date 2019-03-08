#include<cstdio>
using namespace std;
int in[100010];
long long ans=0;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
       scanf("%d",&in[i]);
       if(in[i]-in[i-1]>0)
         ans+=in[i]-in[i-1];
    }
    printf("%lld\n",ans);
    return 0;
}
