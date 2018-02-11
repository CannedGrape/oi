#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
int n,ans,i,x,y;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	ans=0; y=0;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ans+=x;
		ans-=min(x,y);
		y=x;
	}
	cout<<ans<<endl;
}
/*
5 
2 3 4 1 2
10
5 3 3 2 4 3 1 3 2 4
*/
