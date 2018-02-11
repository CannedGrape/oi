#include<iostream>
#include<cstdio>
using namespace std;
int n,m,s[1001][1001],x;
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	
	cin >> n >> m;
	for(int o=1;o<=m;o++)
	{
	  cin >> x;
	  for(int p=1;p<=x;p++)
	    cin >> s[o][p];
	}
	cout << m;
	return 0;
}
