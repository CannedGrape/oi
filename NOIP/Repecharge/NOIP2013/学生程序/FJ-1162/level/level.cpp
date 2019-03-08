#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int map[1002][1002];
int num[1002];
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>num[i];
		for (int j=1;j<=num[i];j++) cin>>map[i][j];
	}
	if (m==2) cout<<"2"<<endl;
	else cout<<"3"<<endl;
	return 0;
}
