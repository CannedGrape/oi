#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#define N 110000
using namespace std;

struct asdf
{
	int data,pos;
	bool operator < (const asdf &w) const
	{
		return data<w.data;
	}
};

asdf a1[N],a2[N];
int i,j,k,p1[N],p2[N],ans=0,n;

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
    cin >> n;
	for (i=1; i<=n; i++)  cin >> a1[i].data;	
	for (i=1; i<=n; i++)  cin >> a2[i].data;
	for (i=1; i<=n; i++)  a1[i].pos=a2[i].pos=i;
	sort(a1+1,a1+n+1); sort(a2+1,a2+n+1);
	for (i=1; i<=n; i++)
	{
		p1[a1[i].pos]=i;
		p2[a2[i].pos]=i;
	}
	for (i=1; i<n; i++)
	  for (j=i+1; j<=n; j++)
	if ((p1[i]>p1[j])!=(p2[i]>p2[j])) ans++;
	cout << ans%99999997 << endl;
	return 0;
}
