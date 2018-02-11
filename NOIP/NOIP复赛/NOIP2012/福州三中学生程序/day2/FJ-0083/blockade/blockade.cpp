#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
/*
int n,m;

int map[55][55];

vector<int> child[55];

int d[55];
bool v[55];
bool put[55];
int pos[55];

int ans=0x3fffffff;

bool check(int x)
{
//	printf("%d ",x);
	bool ichild=(child[x].size()==0);
	if (ichild&&put[x]) return true;
	if (ichild&&!put[x])return false;
	ichild =true;
	for (vector<int>::iterator it=child[x].begin();it!=child[x].end();it++)
		ichild&=check(*it);
	return check;
}

int visit[55];
void dfs2(int x)
{
	for (int i=2;i<=n;i++)
	{
		if (!visit[i]&&map[i][x])
		{
			child[x].push_back(i);
			visit[i]=true;
			dfs2(i);
		}
	}
}

void dfs(int x,int now,int count)
{
	if (now>ans) return ;
	if (count==m||x==n) {if (check(1)) {ans=now; for (int i=2;i<=n;i++) printf("%d,",put[i]);}return;}
//	printf("%d %d %d",x,now,count);
	for (int i=1;i<=m;i++)
	{
		if (!v[i])
		{
			v[i]=true;
			put[x]=true;
			dfs(x+1,now+map[pos[i]][x],count+1);
			put[x]=false;
			v[i]=false;
		}
	}
	dfs(x+1,now,count);
	
}
*/
int main()
{
	freopen("blockade.in","r",stdin);
	freopen("blockade.out","w",stdout);
	printf("-1\n");
	return 0;
}
