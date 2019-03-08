#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MaxN=100001;
const int mod=99999997;

struct match
{
	int height;
	int place;
	int number;
};

match a[MaxN],b[MaxN];
int c[MaxN];
int w[MaxN];
int n;

bool cmp_1(match a,match b)
{
	return a.height<b.height;
}

bool cmp_2(match a,match b)
{
	return a.place<b.place;
}

int t[MaxN];

int lowbit(int x)
{
	return x&(-x);
}

void update(int x)
{
	//cout<<x<<' ';
	for (int i=x;i<=n;i+=lowbit(i))
	{
		t[i]++;
		//cout<<i<<' ';
		//system("pause");
	}
	//cout<<"end"<<endl;
}

int getans(int x)
{
	int ans=0;
	for (int i=x;i>=1;i-=lowbit(i))
	{
		ans=(ans+t[i])%mod;
		//cout<<i<<' ';
	}
	return ans;
}

int tree()
{
	int ans=0;
	for (int i=n-1;i>=0;i--)
	{
		ans=(ans+getans(c[i]))%mod;
		update(c[i]);
		//cout<<ans<<endl;;
	}
	return ans;
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i].height);
		a[i].place=i;
	}
	for (int i=0;i<n;i++)
	{
		scanf("%d",&b[i].height);
		b[i].place=i;
	}
	sort(a,a+n,cmp_1);
	sort(b,b+n,cmp_1);
	a[0].number=0;
	b[0].number=0;
	for (int i=1;i<n;i++)
	{
		//cout<<a[i].height<<' '<<a[i].place<<' '<<b[i].height<<' '<<b[i].place<<endl;
		if (a[i].height==a[i-1].height)
		{
			a[i].number=a[i-1].number;
		}
		else
		{
			a[i].number=i;
		}
		if (b[i].height==b[i-1].height)
		{
			b[i].number=b[i-1].number;
		}
		else
		{
			b[i].number=i;
		}
	}
	sort(a,a+n,cmp_2);
	sort(b,b+n,cmp_2);
	for (int i=0;i<n;i++)
	{
		w[b[i].number]=i;
	}
	for (int i=0;i<n;i++)
	{
		c[i]=w[a[i].number]+1;
//		cout<<c[i]<<' ';
	}
	//cout<<lowbit(1)<<endl;
	printf("%d\n",tree());
	//system("pause");
	return 0;
}
