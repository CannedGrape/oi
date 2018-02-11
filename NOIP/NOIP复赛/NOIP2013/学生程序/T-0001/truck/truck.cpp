#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdlib>
using namespace std;
int n,m,q;
int map[1002][1002];

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		map[a][b]=c; 
	}
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{int x,y; 
		scanf("%d%d",&x,&y);
		printf("%d",map[x][y]);
	}
	return 0;
}
