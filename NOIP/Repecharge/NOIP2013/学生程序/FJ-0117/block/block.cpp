#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
int a[100001];
int n;
long long dp[100001];
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    memset(dp,0,sizeof(dp));
    memset(a,0,sizeof(a));
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
    {
       scanf("%d",&a[i]);
    }
    dp[1]=a[1];
    int minn=a[1];
    for(i=2;i<=n;i++)
    {
       if(a[i]<=minn)
       {
          dp[i]=dp[i-1];
          minn=a[i];
       }
       else
         if(a[i]>=a[i-1])
         {
            dp[i]=dp[i-1]+a[i]-a[i-1];
         }
         else
           dp[i]=dp[i-1];
    }
    cout<<dp[n]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
