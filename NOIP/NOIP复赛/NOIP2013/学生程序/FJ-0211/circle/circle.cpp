#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
const int t = 10;
int a[1000005],flag[1000005],next[1000005],ans;
int n,m,k,x;
int fa(int i,int c)
{
	if(c==t) return i;
	else return fa(flag[i],c+1);
}
int main()
{
freopen("circle.in","r",stdin);
freopen("circle.out","w",stdout);
	int i;
	cin>>n>>m>>k>>x;
    for(i=0;i<=n;i++) a[i]=i;
    for(i=0;i<=n-1;i++) flag[i]=(a[i]+m)%n;
    for(i=0;i<=n-1;i++)	next[i]=fa(i,0);
    if(x==0) cout<<flag[x];
    else 
    {
        ans=x;
        for(i=1;i<=k;i++) ans=next[x];
    	cout<<ans<<"\n";
    }
return 0;
}
