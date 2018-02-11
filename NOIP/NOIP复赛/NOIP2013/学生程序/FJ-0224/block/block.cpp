#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int inf=1<<29;
int n;
int h[100001];
void Init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&h[i]);
}
void slove()
{
	int k=0;
	int ans=0;
	while(k<n)
	{
		int i=1;
		while(h[i]==0) i++;
		while(i<=n)
		{
			int minh=inf;
			int li=i;
			while(h[i]!=0)
			{
				minh=min(minh,h[i]);
				i++;
			}
			bool flag=0;
			for(int j=li;j<i;j++)
			{
				flag=1;
				h[j]-=minh;
				if(h[j]==0) k++;
			}
			if(flag) ans+=minh;
			while(h[i]==0) i++;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	Init();
	slove();
	return 0;
}
