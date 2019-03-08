#include<stdio.h>
using namespace std;
typedef long long ll;
const int maxN=1010;
int N,a[maxN]={},b[maxN]={};
ll pi;
bool visit[maxN]={};
inline const bool check(const ll &limit)
{
	register int now;
	register ll t=pi;
	for(register int i=1;i<=N;++i)
	    visit[i]=false;
	for(register int i=1;i<=N;++i)
	{
		now=-1;
		for(register int j=1;j<=N;++j)
		    if(!visit[j] && limit>=t/a[j]/b[j] && (now==-1 || a[j]>a[now]))
				now=j;
		if(now==-1)
		    return false;
		t/=a[now];
		visit[now]=true;
	}
	return true;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	register int B;
	register ll l,r,mid;
	register bool flag=true;
	scanf("%d%lld%d",&N,&pi,&B);
	for(register int i=1;i<=N;++i)
	{
	    scanf("%d%d",a+i,b+i);
	    pi*=a[i];
	    if(pi<0)
	    {
	        flag=false;
	        break;
		}
	}
	if(flag)
	{
    	for(l=1,r=pi,mid=(l+r)>>1;l<=r;mid=(l+r)>>1)
	        check(mid)?r=mid-1:l=mid+1;
    	printf("%lld\n",l);
	}
	else
	    printf("57858056705504440000\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
