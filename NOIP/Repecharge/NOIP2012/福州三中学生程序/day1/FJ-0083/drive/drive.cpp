#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;
long long x0,s0,si,xi,n;
struct city{
	long long height;
	int pos;
}h[10010];
int toh[10010];
bool inline cmp1(city a,city b)
{
	return (a.height<b.height)||(a.height==b.height&&a.pos<b.pos);
}
int near[10010],near2[10010];
long long inline myabs(long long x)
{
	return (x<0)?(-x):(x);
}double inline myfabs(double x)
{
	return (x<0)?(-x):(x);
}
void update(int i,int j)
{
	if (h[j].pos<=h[i].pos) return;
	if (near[i]==0) {near[i]=j;return;}
	if (near2[i]==0) {near2[i]=j;return;}
	if (myabs(h[i].height-h[near[i]].height)>myabs(h[i].height-h[j].height)
	||((myabs(h[i].height-h[near[i]].height)==myabs(h[i].height-h[j].height)&&h[j].height<h[near[i]].height)
	))
	{
		near2[i]=near[i];
		near[i]=j;
		return ;
	}
	if (myabs(h[i].height-h[near2[i]].height)>myabs(h[i].height-h[j].height)
	||((myabs(h[i].height-h[near2[i]].height)==myabs(h[i].height-h[j].height)&&h[j].height<h[near2[i]].height)
	))
	{
		near2[i]=j;
		return ;
	}
}
int main()
{
	freopen("drive.in","r",stdin);
	freopen("drive.out","w",stdout);
	
	scanf("%lld",&n);
	
	for (int i=1;i<=n;i++) {scanf("%lld",&h[i].height);h[i].pos=i;}
	
	sort(h+1,h+1+n,cmp1);
	for (int i=1;i<=n;i++) toh[h[i].pos]=i;
	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i-j>=1) update(i,i-j);
			if (i+j<=n) update(i,i+j);
		}
	}
//	for (int i=1;i<=n;i++) printf("Height[%d]=%lld\n",h[i].pos,h[i].height);
//	for (int i=1;i<=n;i++) printf("Near[%d]=%d ,Near2[%d]=%d \n",h[i].pos,h[near[i]].pos,h[i].pos,h[near2[i]].pos);
	scanf("%lld",&x0);
	int bestS=0;
	int bestA=0;
	int bestB=0;
	for (int i=1;i<=n;i++)
	{
		bool flag=false; // false A true B
		long long dist=0;int now=i;
		long long distA=0,distB=0;
		while (dist<=x0)
		{		
			if (flag)
			{
				// Xiao B
				if (near[now]==0) break;
				int len=myabs(h[now].height-h[near[now]].height);
				if (dist+len>x0) break;
				distB+=len;
				dist+=len;
				now=near[now];
			}
			else
			{
				if (near2[now]==0) break;
				int len=myabs(h[now].height-h[near2[now]].height);
				if (dist+len>x0) break;
				distA+=len;
				dist+=len;
				now=near2[now];
			}
			flag=!flag;
		}
//		printf("From %d the distA: %d the distB: %d\n",h[i].pos,distA,distB);
		if (distB==0&&bestB==0&&h[bestS].height<h[i].height)
		{
			bestA=distA;bestB=distB;bestS=i;continue;
		}
		if (distA==0&&bestA==0&&h[bestS].height<h[i].height)
		{
			bestA=distA;bestB=distB;bestS=i;continue;
		}
		if (bestA==0||bestB==0 || (distA/(double)distB<bestA/(double)bestB) || (myfabs(distA/(double)distB-bestA/(double)bestB)<1e-9 && h[i].height>h[bestS].height) )
		{
			bestA=distA;bestB=distB;bestS=i;
		}

	}
	printf("%d\n",h[bestS].pos);
	int m;
	scanf("%d",&m);
	while (m--)
	{
		scanf("%lld%lld",&si,&xi);
		bool flag=false; // false A true B
		x0=xi;
		long long dist=0;int now=toh[si];
// 		printf("From :%d(%d) ",toh[si],si);
		long long distA=0,distB=0;
		while (dist<=x0)
		{		
			if (flag)
			{
				// Xiao B
				if (near[now]==0) break;
				int len=myabs(h[now].height-h[near[now]].height);
				if (dist+len>x0) break;
				distB+=len;
				dist+=len;
				now=near[now];
			}
			else
			{
				if (near2[now]==0) break;
				int len=myabs(h[now].height-h[near2[now]].height);
				if (dist+len>x0) break;
				distA+=len;
				dist+=len;
				now=near2[now];
			}
			flag=!flag;
		}
		printf("%lld %lld\n",distA,distB);
	}
	return 0;
}
