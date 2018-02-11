#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define N 2*10003
using namespace std;
int n,m,q,head[N],v[N],tail[N],p[N];
void spfa(int e,int v)
{
}
void init()
{
	int a,b,c,d=0;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
		scanf("%d%d%d",&a,&b,&c);
		p[++d]=b,tail[d]=head[a],head[a]=d,v[d]=c;
		p[++d]=a,tail[d]=head[b],head[b]=d,v[d]=c;
	}
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
	   scanf("%d%d",&a,&b);
	   spfa(a,b);
	}
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	init();
	//system("pause");
	return 0;
}
//bingcha 
