#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<math.h>
#include<vector>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
#define ifn(x) if(!x)
typedef long long ll;
const ll llinf=0x7fffffffffffffffll;
const int inf=0x3fffffff,upinf=0x7fffffff;
const double dinf=1e20,eps=1e-12;

ll n,height[100001];
ll ans=0;
void Init()
{
     scanf("%lld",&n);
     height[0]=0; rep(i,1,n) scanf("%lld",&height[i]);
}
void Greed()
{
     rep(i,1,n)   if(height[i-1]<height[i]) ans+=height[i]-height[i-1];
     printf("%lld\n",ans);
}
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    Init();
    Greed();
    fclose(stdin); fclose(stdout);
    return 0;
}
