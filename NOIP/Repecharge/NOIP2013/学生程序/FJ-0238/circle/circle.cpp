#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
	for(int i=b;i<=a*b;i++)
	  if((i%a==0)&&(i%b==0))return i; 
}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	int n,m,k,x,y;
	ios::sync_with_stdio(false);
	cin>>n>>m>>k>>x;
	int l=gcd(m,n)/m;
	y=1;
	for(int i=1;i<=k;i++)
	  y=y*10%l;
	for(int i=1;i<=y;i++)
	   x=(x+m)%n;
	cout<<x;
	return 0;
} 
