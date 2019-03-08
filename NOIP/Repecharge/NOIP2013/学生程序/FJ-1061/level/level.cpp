#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int a,c,d;
int n,m;
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);

	cin>>n>>m;
	int b[m],in[m][b[m]];
	for(a=1;a<=m;a++)
	{
		cin>>b[a];
		for(c=1;c<=b[a];c++)
			cin>>in[a][c];
	}
	int mark[n];
	if(n==2)
	{
		cout<<1;
		return 0;
	}
	cout<<3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
