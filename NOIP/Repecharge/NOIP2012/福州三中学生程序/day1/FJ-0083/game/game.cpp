/* ORZ All RP++*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <climits>
using namespace std;
/*
	Get=Max{Mul[x-1]/Right[x]}
	Min(Get)
	(x1,y1) (x2,y2) ... (xi,yi) ... (xn,yn)
	x1*x2*...xi-1 / yi => max
	x1*x2*...xi-1 / yi > x1*x2*...xi-2 / yi - 1
	x1*x2*...xi-1 / yi > x1*x2*...xi   / yi + 1
	x1*x2*...xi-2 / yi
	x1*x2*...xi-1 / yi-1
	???
*/
struct po{
	int left,right;
}pp[1010];int n;
bool inline cmp1(po l,po r)
{
	return (l.right<r.right)||(l.right==r.right&&l.left<r.left);
}bool inline cmp2(po l,po r)
{
	return (l.left<r.left)||(l.left==r.left&&l.right<r.right);
}bool inline cmp3(po l,po r)
{
	return (l.left<r.left)||(l.left==r.left&&l.right>r.right);
}bool inline cmp4(po l,po r)
{
	return (l.right<r.right)||(l.right==r.right&&l.left<r.left);
}
bool inline cmp5(po l,po r)
{
	return (l.left*r.right<r.left*l.right);
}
bool v[11];long long rst=282475250; // 7^10
//                  (int)2147483647
void dfs(int pi,int ans,int sum)
{
	if (ans>rst) return ;
	if (pi==n) {rst=ans;return ;}
	for (int i=1;i<=n;i++)
	{
		if (!v[i])
		{
			v[i]=true;
			dfs(pi+1,max(ans,sum/pp[i].right),sum*pp[i].left);
			v[i]=false;
		}
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	scanf("%d%d",&pp[0].left,&pp[0].right);
	for (int i=1;i<=n;i++) 
		scanf("%d%d",&pp[i].left,&pp[i].right);
		
	if (n<=10)
		dfs(0,0,pp[0].left);
	else
	{
		sort(pp+1,pp+n+1,cmp1);
		long long nsum=pp[0].left;
		long long nans=0;
		for (int i = 1;i<=n;i++)
		{
			nans=max(nans,nsum/pp[i].right);
			nsum*=pp[i].left;
		}
		sort(pp+1,pp+n+1,cmp2);
		nsum=pp[0].left;
		long long 	nans1=nans;nans=0;
		for (int i = 1;i<=n;i++)
		{
			nans=max(nans,nsum/pp[i].right);
			nsum*=pp[i].left;
		}
		sort(pp+1,pp+n+1,cmp3);
		nsum=pp[0].left;
		long long nans2=nans;nans=0;
		for (int i = 1;i<=n;i++)
		{
			nans=max(nans,nsum/pp[i].right);
			nsum*=pp[i].left;
		}
		sort(pp+1,pp+n+1,cmp5);
		nsum=pp[0].left;
		long long nans3=nans;nans=0;
		for (int i = 1;i<=n;i++)
		{
			nans=max(nans,nsum/pp[i].right);
			nsum*=pp[i].left;
		}
		sort(pp+1,pp+n+1,cmp4);
		nsum=pp[0].left;
		long long 	nans4=nans;nans=0;
		for (int i = 1;i<=n;i++)
		{
			nans=max(nans,nsum/pp[i].right);
			nsum*=pp[i].left;
		}
		rst=min(min(min(nans2,min(nans1,nans)),nans3),nans4);
	}
	printf("%lld\n",rst);
	return 0;
}
