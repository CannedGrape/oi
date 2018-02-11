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

int n,h[100001];
int f[100001][2],g[100001][2];
void Init()
{
     scanf("%d",&n);
     rep(i,1,n) scanf("%d",&h[i]);
     rep(i,1,n) f[i][0]=f[i][1]=g[i][0]=g[i][1]=1;
}
void DP()
{
     rep(i,1,n)
               rep(j,1,i-1)
                           {
                                 if(h[j]>h[i])
                                              f[i][1]=max(f[i][1],f[j][0]+1);
                                 if(h[j]<h[i])
                                              f[i][0]=max(f[i][0],f[j][1]+1);
                           }
     rep(i,1,n)
               rep(j,1,i-1)
                           {
                                 if(h[j]<h[i])
                                              g[i][1]=max(g[i][1],g[j][0]+1);
                                 if(h[j]>h[i])
                                              g[i][0]=max(g[i][0],g[j][1]+1);
                           }
     int ans=0;
     rep(i,1,n) ans=max(ans,max(max(f[i][0],f[i][1]),max(g[i][0],g[i][1])));
     printf("%d\n",ans);
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    Init();
    DP();
    fclose(stdin); fclose(stdout);
    return 0;
}
