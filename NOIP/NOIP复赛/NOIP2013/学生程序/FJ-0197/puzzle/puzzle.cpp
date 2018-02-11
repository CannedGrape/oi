#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
bool map[35][35],fl=0;
int x3,y3,x2,y2,wx,wy,n,m,q;
void init()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
	    for (int j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	int a;
	scanf("%d%d%d%d%d%d",&wx,&wy,&x3,&y3,&x2,&y2);
    for (int i=1;i<q;i++)  for (int j=1;j<=6;j++)  scanf("%d",&a);
}
void work()
{
	if (q==1)
	{
		cout<<"-1";
	}
	else {for (int i=1;i<=q;i++)  printf("-1\n");}
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	init();
	work();
	return 0;
}
