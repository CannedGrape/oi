#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<queue>

using namespace std;

const int Maxn=1000010;

int n,m,k,x,len=0,tk;
int p[Maxn];
bool vis[Maxn];

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	
	scanf(" %d %d %d %d",&n,&m,&k,&x);
	for(int i=0;i<n;i++) vis[i]=true;
	for(int i=x;vis[i];i=(i+m)%n)
	{
		vis[i]=false; p[len++]=i;
	}
	//for(int i=0;i<len;i++) printf("%d ",p[i]);
	
	for(int i=0;i<n;i++) vis[i]=true;
	tk=1; int j,tl=0;
	for(j=1;j<=k;j++)
	{
		if(!vis[tk]) break;
		tl++;
		vis[tk]=false;
		tk=tk*10%len;
	}
	
	if(j>k) printf("%d\n",p[tk]);
	else printf("%d\n",p[k%tl]);
	
	//system("pause");
	return 0;
}

