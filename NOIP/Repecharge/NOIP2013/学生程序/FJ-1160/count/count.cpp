#include<cstdio>
using namespace std;

int n,x,ans=0;

int main()
{
	freopen("count.in","r",stdin);freopen("count.out","w",stdout);
	scanf("%d%d",&n,&x);
	for(int y;y=n--;) for(;y;y/=10) if((y%10)==x) ++ans;
	printf("%d",ans);
	return 0;
}
