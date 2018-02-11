#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,a[100001];
long long ans;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int i;
    cin>>n;
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    a[0]=0;
    for (i=1;i<=n;i++)
      if (a[i]>a[i-1])
        ans+=a[i]-a[i-1];
    cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
}
