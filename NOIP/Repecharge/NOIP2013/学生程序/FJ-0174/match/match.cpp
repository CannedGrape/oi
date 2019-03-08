#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=100010;
class ck
{
	public:
		int x,y;
}a[maxn],b[maxn];
bool found[maxn];
/*
class ck1
{
	public:
		int x,pos;
}b[maxn];*/

int n,m,k;

void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].x);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].y);
}

bool cpr(ck a,ck b)
{
	return a.x<b.x;
}
void qsort(int x,int y)
{
	int p=x,q=y;
	ck t=a[(x+y)>>1];
	while (x<y)
	{
		while (cpr(a[x],t)) ++x;
		while (cpr(t,a[y])) --y;
		if (x<=y)  swap(a[x++],a[y--]);
	}
	if (x<q) qsort(x,q);
	if (p<y) qsort(p,y);
}
void qsort1(int x,int y)
{
	int p=x,q=y;
	ck t=b[(x+y)>>1];
	while (x<y)
	{
		while (cpr(b[x],t)) ++x;
		while (cpr(t,b[y])) --y;
		if (x<=y)  swap(b[x++],b[y--]);
	}
	if (x<q) qsort1(x,q);
	if (p<y) qsort1(p,y);
}

void sort_b()
{
	for (int i=1;i<=n;i++)
	{
		b[i].x=a[i].y;
		b[i].y=i;
	}
	qsort1(1,n);
	for (int i=1;i<=n;i++) a[b[i].y].y=i;
}//ÀëÉ¢ 

void solve()
{
	int count=0,ans=0;
	for (int i=1;i<=n;i++) 
		if (a[i].y!=i) ++ans;
	for (int i=1;i<=n;i++) found[i]=0;
	for (int i=1;i<=n;i++)
		if (a[i].y!=i && !found[i])
		{
			++count;
			found[i]=1;
			int k=i;
			while (!found[a[k].y])
			{
				k=a[k].y;
				found[k]=1;
			}
		}
//	cout<<ans<<endl;
//	cout<<count<<endl;
	printf("%d\n",ans-count);
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	init();
	qsort(1,n);
	sort_b();
	solve();
	return 0;
}
