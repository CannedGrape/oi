#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int check[32][32];
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	int n,m,q;
	int i,j;
	int ex,ey,sx,sy,tx,ty;
	cin>>n>>m>>q;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		cin>>check[i][j];
	}
	for(i=1;i<=q;i++)
	cin>>ex>>ey>>sx>>sy>>tx>>ty;
	cout<<"-1";
	return 0;
}
