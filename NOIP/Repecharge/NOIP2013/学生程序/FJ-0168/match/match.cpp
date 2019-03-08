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
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),num[i]=a[i];
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++)a[i]=lower_bound(num+1,num+1+n,a[i])-num,posa[a[i]]=i;
	
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),num[i]=b[i];
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=lower_bound(num+1,num+1+n,b[i])-num;
		//if(!(1<=b[i]&&b[i]<=n)){cerr<<"ccc";while(1);}
		b[i]=posa[b[i]];
	}
	
	/*for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		int j=i,cnt=0;
		while(!vis[j])
		{
			vis[j]=1;
			j=posa[b[j]];
			cnt++;
		}
		ans+=cnt-1;
	}*/
	/*for(int i=1;i<=n;i++)
	if(!(1<=a[i]&&a[i]<=n)){cerr<<"aaa";while(1);}
	for(int i=1;i<=n;i++)
		if(!(1<=b[i]&&b[i]<=n)){cerr<<"eee "<<b[i];while(1);}*/
	for(int i=n;i>=1;i--)
	{
		ans+=ask(b[i]-1);
		add(b[i]);
		ans%=mod;
	}
	printf("%d\n",ans);
	return 0;
}
