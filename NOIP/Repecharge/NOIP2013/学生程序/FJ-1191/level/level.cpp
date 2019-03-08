#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m;
char ram1[1001];
void scan()
{
	scanf ("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		gets(ram1);
	}
}
void sum()
{
	
}
void print()
{
	printf ("%d",m);
} 
int main()
{
	freopen ("level.in","r",stdin);
	freopen ("level.out","w",stdout);
	scan();
	sum();
	print();
	//system ("pause");
	return 0;
}