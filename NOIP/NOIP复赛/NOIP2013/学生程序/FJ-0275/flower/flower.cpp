#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define INF 10000000
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int T;scanf("%d",&T);
	bool upon1=1,upon2=0;
	int last1=-1,now;
	int last2=INF;
	long long ans1=0,ans2=0;
	
	while(T--)
	{
		scanf("%d",&now);
		if(upon1==1)
		{
			if(now<last1){upon1=0;ans1++;}
			last1=now;
		}
		else
		{
			if(now>last1){upon1=1;ans1++;}
			last1=now;
		}
		if(upon2==1){
			if(now<last2){upon2=0;ans2++;}
			last2=now;
		}
		else
		{
			if(now>last2){upon2=1;ans2++;}
			last2=now;
		}
	}
	printf("%lld\n",max(ans1,ans2)+1);
	return 0;
}
