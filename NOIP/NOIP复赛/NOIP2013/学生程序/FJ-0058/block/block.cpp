#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define P 100010

using namespace std;

int a[P],n;
long long s[P];
long long x,y;

int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i = 1;i <= n;i++) scanf("%d",&a[i]);
    for(i = 1;i <= n;i++) s[i] = a[i] - a[i - 1];
    for(i = 1;i <= n;i++)
    {
          if(s[i] > 0) x += s[i];
          else y -= s[i];
    }
    printf("%lld\n",max(x,y));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
