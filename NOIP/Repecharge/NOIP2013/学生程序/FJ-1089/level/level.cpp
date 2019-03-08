#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int level[1001]={1},n,m,st[1001][1001]={0},i,j,b,k,ans=0;
bool ji[1001]={false};
void check(int num)
{
     for(j=1;j<=n;j++)
		 if((st[j][num]==1)&&(level[j]<=level[j+1]))
	         for(k=1;k<=n;k++)
				 if(st[k][num]==1)level[k]++;
}
void tongji()
{
	 for(j=1;j<=n;j++)
	ji[level[j]]=true;
	 for(j=1;j<=n;j++)ans+=ji[j];
}
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>st[i][0];
		for(j=1;j<=st[i][0];j++)
		{cin>>b;
		st[j][b]=1;}
	}
	for(i=1;i<=m;i++)
	check(i);
	tongji();
	cout<<ans+1;
	fclose(stdin);
	fclose(stdout);
	//system("pause");
	return 0;
}