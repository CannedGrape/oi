#include<cstdio>
#define lowbit(x) x&(-x)
int n,ans;
int h[100010];
int dp[100100][2];
int tree0[1100000],tree1[1100000];
int ask0(int now)
{
	int ret=0;
	for(;now;now-=lowbit(now))
		if(tree0[now]>ret)
			ret=tree0[now];
	return ret;
}
void change0(int now,int val)
{
	for(;now<=1000010;now+=lowbit(now))
		if(tree0[now]<val)
			tree0[now]=val;
}
int ask1(int now)
{
	int ret=0;
	for(;now<=1000010;now+=lowbit(now))
		if(tree1[now]>ret)
			ret=tree1[now];
	return ret;
}
void change1(int now,int val)
{
	for(;now;now-=lowbit(now))
		if(tree1[now]<val)
			tree1[now]=val;
}
int main()
{
	int i;
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",h+i);
		++h[i];
	}
	for(i=1;i<=n;++i)
	{
		dp[i][0]=ask1(h[i]+1)+1;
		dp[i][1]=ask0(h[i]-1)+1;
		if(dp[i][0]==0)
			dp[i][0]=1;
		if(dp[i][1]==0)
			dp[i][1]=1;
		change0(h[i],dp[i][0]);
		change1(h[i],dp[i][1]);
		if(dp[i][0]>ans)
			ans=dp[i][0];
		if(dp[i][1]>ans)
			ans=dp[i][1];
	}
	printf("%d\n",ans);
	return 0;
}
