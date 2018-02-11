#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[210][100000];
int main()
{
	int n,m,l,k;
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>l;
		for(int j=1;j<=l;j++)
		cin>>a[i][j];
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
}
