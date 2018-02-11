#include <cstdio>
#include <cstdlib>

using namespace std;

#define N 100010

int n,h[N],max=0,min=N,ans=0,t,j,x[N];

int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		x[i]=i;
		scanf("%d",&h[i]);
		if (h[i]>max) max=h[i];
		if ((h[i])&&(h[i]<min)) min=h[i];
	}
	while (max)
	{
		t=min,max-=t,min=N,j=x[1];
		if (h[n]) ans+=t;
		while (!h[j]) ++j;
		x[1]=j;
		for (int i=j;i<=n;)
			if (h[i])
			{
				h[i]-=t;
				if ((h[i])&&(h[i]<min)) min=h[i];
				++i;
			}
			else
			{
				ans+=t,i=x[i];
				while ((!h[i])&&(i<=n)) ++i;
				x[i]=i;
			}
	}
	printf("%d\n",ans);
	return 0;
}
