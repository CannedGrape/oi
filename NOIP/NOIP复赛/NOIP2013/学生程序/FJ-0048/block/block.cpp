#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

  int a[100010];
  int n,ans;

int main()
{
    int i;
    
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d",&n);
    a[0]=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=1;i<=n;i++)
    {
        if (a[i]>a[i-1])
        {
                        ans=ans+a[i]-a[i-1];
        }
    }
    printf("%d",ans);
    return 0;
}
