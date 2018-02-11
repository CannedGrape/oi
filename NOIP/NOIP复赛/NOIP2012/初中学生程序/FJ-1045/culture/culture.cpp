#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
int n,k,m,s,t,c[101],ga[101][101],f[101][101];
bool dl[101][101];
void culture()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(ga[i][j]!=0 && !dl[c[i]][c[j]])
				f[i][j]=ga[i][j];
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int m=1;m<=n;m++)
				if(f[i][m]+f[m][j]<f[i][j] && f[i][m]!=0 && f[m][j]!=0)
					f[i][j]=f[i][m]+f[m][j];
		}
	}
}
int main()
{
	freopen("culture.in","r",stdin);
	freopen("culture.out","w",stdout);
	cin>>n>>k>>m>>s>>t;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			cin>>dl[i][j];
	for(int i=1;i<=m;i++)
	{
		int u,v,d;
		cin>>u>>v>>d;
		ga[u][v]=d;
		ga[v][u]=d;
	}
	culture();
	if(f[s][t]==0)
		cout<<"-1"<<endl;
	else
		cout<<f[s][t]<<endl;
	fclose(stdout);
	return 0;
}
