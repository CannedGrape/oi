#include <iostream>
#include <cstdio>
using namespace std;
int a,b,c;
int a1[10000][10000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<100;j++)
		{
			cin>>a1[i][j];
		} 
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
}
