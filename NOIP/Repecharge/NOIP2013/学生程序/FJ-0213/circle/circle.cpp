#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
using namespace std;
long long n,m,k,x,i,ans,y,y2,l;
bool f[100];
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	for (i=0;i<100;i++)f[i]=false;
	cin>>n>>m>>k>>x;
	y=1; y2=0;
	while (y<=k) {y*=2; y2++;}
	y/=2; y2--; l=y2;
	while (k>0)
	{
		 if (k>=y){k-=y; f[y2]=true;}
		 y2--; y/=2;
	}
	y=10; ans=m;
	for (i=0;i<=l;i++)
	{
		if (f[i]) {ans*=y; ans%=n;}
		y*=y; y%=n;
	}
	ans+=x; ans%=n;
	cout<<ans;
}
