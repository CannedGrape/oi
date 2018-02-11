#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
const int mod = 99999997;
int n,ans=0;
long long a[100005],b[100005],f1[100005],f2[100005];
bool cmp1(long long x,long long y){return a[x]<a[y];}
bool cmp2(long long x,long long y){return b[x]<b[y];}
int check(int x){for(int i=1;i<=n;i++) if(f1[i]==x) return i;}
void find()
{
	int i,j; 
	for(i=1;i<=n;i++)
	{
		if(f1[i]==f2[i]) continue;
		int now,pre,temp;
		pre=i;
		while(f1[i]!=f2[i])
		{
			ans++;
			ans%=mod;
		    now=check(f2[pre]);
		    temp=f1[pre];f1[pre]=f1[now];f1[now]=temp;
		    pre=now;
		}
	}
}
int main()
{
freopen("match.in","r",stdin);
freopen("match.out","w",stdout);
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),f1[i]=i;
	for(i=1;i<=n;i++) scanf("%lld",&b[i]),f2[i]=i;
	sort(f1+1,f1+1+n,cmp1);
	sort(f2+1,f2+1+n,cmp2);
	find();
	cout<<ans<<"\n";
return 0;
}
