#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int n,m,k,x;
    scanf("%d%d%d%d",&n,&m,&k,&x);
    int ans=1,a=10;
    while(k)
    {
      if(k&1)
      {
        ans=(ans*a)%n;
      }
      a=(a*a)%n;
      k/=2;
    }
    ans=(ans*m)%n;
    ans=(ans+x)%n;
    printf("%d\n",ans);
    return 0;  
}
