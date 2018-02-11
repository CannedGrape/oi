#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int n,m,sz[1015],t,gs;
bool a;
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	memset(sz,0,sizeof(sz));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
	  cin>>gs;
	  for(int j=1;j<=gs;j++)
	  {
	    cin>>t;
	    sz[t]++;
	  }
	}
	sort(sz+1,sz+1+n);
	cout<<sz[n]<<endl;
	return 0;
}
