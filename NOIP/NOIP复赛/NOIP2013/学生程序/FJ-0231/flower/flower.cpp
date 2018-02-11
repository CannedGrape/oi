#include<iostream>
#include<cstdio>
using namespace std;
int n,h[100001],m=3,g[100001];
int c,d;
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {scanf("%d",&h[i]);g[i]=h[i];}
	for(i=2;i<n;i++) if (g[i]<g[i+1] && g[i]<g[i-1]) c++;
	for(i=2;i<n;i++) if (g[i]>g[i+1] && g[i]>g[i-1]) d++;
	c=c>d?c:d;
	m=2*c+1;
	printf("%d",m);
	return 0;
	}
