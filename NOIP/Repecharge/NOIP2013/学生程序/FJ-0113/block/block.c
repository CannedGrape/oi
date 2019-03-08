#include<stdio.h>
#include<stdlib.h>
int n,a[100010],b[100010];
long long ans=0;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=n+1;i++)
    {
        b[i]=a[i]-a[i-1];
        if(b[i]>0) ans+=b[i];
    }
    printf("%lld\n",ans);
    return 0;
}
