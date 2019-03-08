#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

  int h[100010];
  int n,ans;

int main()
{
    int i,t;
    
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }
    ans=0;
    for (i=2;i<=n-1;i++)
    {
        if (h[i-1]<h[i] && h[i+1]<h[i])
        {
                        ans++;
        }
        if (h[i-1]>h[i] && h[i+1]>h[i])
        {
                        ans++;
        }
    }
    t=1;
    for (i=1;i<=n-1;i++)
    {
        if (h[i]!=h[i+1])
        {
                         t=0;
        }
    }
    if (t==0)
    {
             ans=ans+2;
    }
    else
    {
        ans=ans+1;
    }
    printf("%d",ans);
    return 0;
}
