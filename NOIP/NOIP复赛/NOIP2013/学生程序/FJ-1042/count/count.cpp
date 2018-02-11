#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
long long tot;
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int n,m,ans;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; ++i)
    {
        ans=i;
        while(ans)
        {
            if (ans%10==m) ++tot;
            ans=ans/10;
        }
    }
    printf("%lld",tot);
    fclose(stdin); fclose(stdout);
}
