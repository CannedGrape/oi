#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m,a[1000];
	freopen("level.in","r",stdin);
	freopen("level.in","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	cout<<m;
	fclose(stdin);
	fclose(stdout);
}
