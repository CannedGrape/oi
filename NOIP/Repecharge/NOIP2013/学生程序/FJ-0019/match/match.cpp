#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define P 99999997
#define MAXN 100010
#define lowbit(x) x&(-x)
using namespace std;
struct edge
{
	int num,posi;
}num1[MAXN],num2[MAXN];
long long ans,c[MAXN];
int a[MAXN],b[MAXN],n,posi1[MAXN],posi2[MAXN];
bool cmp(edge a1,edge b1) {return a1.num<b1.num;}
void add(int t)
{
	for (;t<=n;t+=lowbit(t))
		++c[t];
}
long long find(int t)
{
	long long sum=0;
	for (;t;t-=lowbit(t))
		sum+=c[t];
	return sum;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	long long i,j;
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		num1[i].num=a[i];
		num1[i].posi=i;
	}
	for (i=1;i<=n;++i)
	{
		scanf("%d",&b[i]);
		num2[i].num=b[i];
		num2[i].posi=i;
	}
	sort(num1+1,num1+1+n,cmp);
	sort(num2+1,num2+1+n,cmp);
	for (i=1;i<=n;++i)
		posi1[num1[i].posi]=i;
	for (i=1;i<=n;++i)
	{
		j=num2[posi1[i]].posi;
		j-=find(j);
		ans+=j-1;
		ans%=P;
		add(num2[posi1[i]].posi);
	}
	cout<<ans;
	//system("pause");
	return 0;
}
