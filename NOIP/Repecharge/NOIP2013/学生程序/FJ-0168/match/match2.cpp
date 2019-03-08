#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
int get()
{
	int f=0,v=0;char ch;
	while(!isdigit(ch=getchar()))if(ch=='-')break;
	if(ch=='-')f=1;else v=ch-'0';
	while(isdigit(ch=getchar()))v=v*10+ch-'0';
	if(f==1)return -v;else return v;
}
const int maxn=100003,mod=99999997;
int a[maxn],b[maxn],n,num[maxn],posa[maxn],ans=0,c[maxn];
bool vis[maxn];

void add(int x)
{
	for(;x<=n;x+=x&-x)c[x]++;
}
int ask(int x)
{
	int res=0;
	for(;x;x-=x&-x)res+=c[x];
	return res;
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match2.out","w",stdout);
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),num[i]=a[i];
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++)a[i]=lower_bound(num+1,num+1+n,a[i])-num,posa[a[i]]=i;
	
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),num[i]=b[i];
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=lower_bound(num+1,num+1+n,b[i])-num;

		b[i]=posa[b[i]];
	}
	
	
	/*for(int i=n;i>=1;i--)
	{
		ans+=ask(b[i]-1);
		add(b[i]);
		ans%=mod;
	}*/
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(b[i]>b[j])ans++,ans%=mod;
	printf("%d\n",ans);
	return 0;
}
