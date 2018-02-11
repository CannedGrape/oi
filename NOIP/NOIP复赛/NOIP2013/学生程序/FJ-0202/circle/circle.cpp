#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
int n,m,k,x,s=10;
int cc(int v)
{   if(v==1)return s;
	int y=v/2,t=1,d;
	if(v%2)t=s;
	d=cc(y)%n;
	t=t*d%n*d%n;
	return t;}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k>>x;
    cout<<(x%n+cc(k)*m%n)%n;
  return 0;
}

