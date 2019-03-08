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
using namespace std;

long long n,m,k,x,ans,i;

long long work(long long t)
{
	if (t==1) return 10%n;
	long long b=work(t/2);
	long long ans1=(b*b)%n;
	if (t%2==1) ans1=(ans1*10)%n;
	return ans1;
}

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	cin >> n >> m >> k >> x;
	ans=work(k);
	cout << (m*ans+x)%n << endl;
	return 0;
}
