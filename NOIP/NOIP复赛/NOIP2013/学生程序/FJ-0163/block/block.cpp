#include <iostream>
#include <stdio.h>
using namespace std;
const int maxn = 100001;
long long  ans,n,a[maxn];
int main(){
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
      scanf("%lld",&n);
    for(int i=1;i<=n;i++)
      scanf("%lld",&a[i]);
    a[0]=0;ans=0;
    for(int i=1;i<=n;i++)
      if(a[i]>a[i-1])
        ans=ans+(a[i]-a[i-1]);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
