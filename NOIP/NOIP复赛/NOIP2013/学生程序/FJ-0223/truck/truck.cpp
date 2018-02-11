//rp++
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;
int i,j,n,m,k,l,q,x,y,z;
int f[1010][1010];
bool ff[1010];
int ma(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int mi(int a,int b)
{
	if(a>b) return b;
	else return a;
}
void dij(int l)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(f[l][i]>0)
		{
			for(j=1;j<=n;j++)
			{
				if(f[i][j]>0)
				{
					if(mi(f[l][i],f[i][j])>f[l][j]) f[l][j]=mi(f[l][i],f[i][j]);
				}
			}
		}
    }
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(f,0,sizeof(f));
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		f[x][y]=ma(f[x][y],z);
		f[y][x]=f[x][y];
	}
	memset(ff,true,sizeof(ff));
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{   
		scanf("%d%d",&x,&y);
		if(ff[y]==false||ff[x]==false)
		{
			if(f[x][y]>0) cout<<f[x][y]<<endl;
			else cout<<-1<<endl;
			continue;
			
		}
		else
		{
			dij(x);
			ff[x]=false;
			if(f[x][y]>0) cout<<f[x][y]<<endl;
			else cout<<-1<<endl;
		}
	}
}

