#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int T;scanf("%d",&T);
	int last=0,now;
	long long ans=0;
	while(T--)
	{
		scanf("%d",&now);
		if(now<last){last=now;continue;}
		else {ans+=now-last;last=now;}
	}
	printf("%lld\n",ans);
	return 0;
}
