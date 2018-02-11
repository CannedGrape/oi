#include <stdio.h>
int n,list[100001] = {0};
long long ans = 0;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int i;
    long long num;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&list[i]);
        num = (long long)(list[i]-list[i-1]);
        if(num>0) ans += num;
    }
    printf("%lld\n",ans);
    return 0;
}
