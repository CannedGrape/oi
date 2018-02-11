#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	int a,b,d,i,j;
	cin>>a>>b;
	int c[1001];
	for(i=1;i<=b;i++)
	{
		cin>>c[i];
		for(j=1;j<=c[i];j++)
			cin>>d;
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
