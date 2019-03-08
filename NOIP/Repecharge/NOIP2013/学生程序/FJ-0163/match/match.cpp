#include <iostream>
#include <stdio.h>
using namespace std;
const int P = 99999997;
int n,ans;
long long a[100001],b[100001];
int main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
      scanf("%lld",&b[i]);
    ans = 0;
    for(int i=1;i<n;i++)
        if(a[i]*b[i]+a[i+1]*b[i+1]<a[i]*b[i+1]+a[i+1]*b[i])
          ans=(ans+1)%P;
    cout<<ans;   
    fclose(stdin);
    fclose(stdout);
    return 0;
}
