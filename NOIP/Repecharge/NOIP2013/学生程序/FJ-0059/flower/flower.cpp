#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)<0?(-(a)):(a))
#define sqr(a) a*a
#define swap(a,b) a^=b;b^=a;a^=b;
#define S 10000
#define MAX 2139062143
#define N 100004
using namespace std;
int n,ll,l2;
int h[N],s[N];
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	if(n<2)
	{
		cout<<n<<endl;
		return 0;
	}
	if(n==2)
	{
		if(h[1]!=h[2])
			cout<<n<<endl;
		else cout<<n-1<<endl;
		return 0;
	}
	s[1]=h[1];s[2]=h[2];
	ll=2;
	for(i=3;i<=n;i++)
	{
		if(s[ll-1]>s[ll])
		{
			if(s[ll]>=h[i])
			{
				s[ll]=h[i];
			}
			else
			{
				s[++ll]=h[i];
			}
		}
		if(s[ll-1]<s[ll])
		{
			if(s[ll]<=h[i])
			{
				s[ll]=h[i];
			}
			else
			{
				s[++ll]=h[i];
			}
		}
	}
	cout<<ll<<endl;
	return 0;
}
