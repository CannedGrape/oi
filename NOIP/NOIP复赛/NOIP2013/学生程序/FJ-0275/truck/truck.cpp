#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool v[1001][1001];
int map[1001][1001],ans[1001][1001];
int N,M;

void BUG()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)cout<<ans[i][j]<<' ';
		cout<<endl;
	}
}

void init()
{
	int a,b,v;
	cin>>N>>M;
	for(int i=1;i<=M;i++)
	{
		cin>>a>>b>>v;
		map[a][b]=map[b][a]=max(map[a][b],v);
		ans[a][b]=ans[b][a]=1;
	}
}
	
void floyd_begin()
{
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				if(ans[i][j]||(ans[i][k]&&ans[k][j]))ans[i][j]=1;
}

bool floyd(int P)
{
	bool is_w=0;
	memset(v,0,sizeof(v));
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if(map[i][j]-P>0||(map[i][k]-P>0&&map[k][j]-P>0))
				{
					if(ans[i][j]==0)ans[i][j]=1;
					else if(!v[i][j])ans[i][j]+=1;
					v[i][j]=1;
					is_w=1;
				}
			}
		}
	}
	if(is_w)return 1;
		else return 0;
}

void solve()
{
	//BUG();
	int T,a,b;
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		if(!ans[a][b])cout<<-1<<endl;
		else cout<<ans[a][b]<<endl;
	}
}

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	memset(ans,0,sizeof(ans));
	init();
        floyd_begin();
	for(int i=1;;i++)
		if(!floyd(i))break;
	solve();
	return 0;
}
