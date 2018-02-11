#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int n,p,s[1000001],maxn,f[1000001],t[1000001],zc,sum;
void work(int k,int c)
{
	sum=0;zc=k;
	for(int i=1;i<=k;i++) t[i]=i;
	for(int i=1;i<=k;i++) 
	{
		sum+=s[t[i]];
		if(sum+s[c]>maxn) maxn=sum+s[c];
	}
	while(t[1]<=c-k+1)
	{
		if(t[k]==c-1) while(zc>1 && s[zc]<c-k+zc+1) zc--;
		if(zc==k) break;
		t[zc]++;
		sum=0;
		for(int i=1;i<=k;i++) 
		{
			sum+=s[t[i]];
			if(sum>maxn) maxn=sum;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		f[i]=f[i-1]+s[i];
	}
	maxn=s[1];
	for(int i=2;i<=n;i++) 
	for(int j=1;j<=i-1;j++)
	{
		work(j,i);
	}
	if(abs(maxn)!=maxn) printf("-");
	printf("%d\n",abs(maxn)%p);
	return 0;
}
