#include <iostream>
#include <cstdio>
using namespace std;
int n,ans=0;
int h[100005];
int main()
{	
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	scanf("%d",&h[i]);
	ans+=h[1];
	for(i=2;i<=n;i++)
	if(h[i-1]<h[i]) ans=ans+h[i]-h[i-1];
	cout<<ans;
	return 0;
}
