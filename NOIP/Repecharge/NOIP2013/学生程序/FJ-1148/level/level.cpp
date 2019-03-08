#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a,j;
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&j);
		for(int k=1;k<=j;k++)scanf("%d",&a);
	}
	cout<<m<<endl;
	return 0;
}