#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
using namespace std;
int main()
{
	int n,m,x,y,df=0;
	bool a[1000][1000]={0},ans[1000]={false};
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	  {cin>>x;
	  for(int j=1;j<=x;j++)
	      {cin>>y;
	      a[i][y]=true;
		}
		}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{if((a[i-1][j]==true&&a[i][j]==false)||(a[i-1][j]==false&&a[i][j]==true))
	 {ans[j]=true;}
		}
	for(int i=1;i<=n;i++)
	 {if(ans[i]==true) df++;
			}
	cout<<df+1<<endl;
	return 0;
}
