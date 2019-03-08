#include<cstdio>
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int i,n,m,k,x,ans;
    scanf("%d%d%d%d",&n,&m,&k,&x);
    ans=x;
    for(i=1;i<=k;i++)
    {
        m=(10*m)%n;
        ans=(ans+m)%n;
    }
    printf("%d\n",ans);
    return 0;
}
