#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge
{
	int v,next,w;
}e[110000],que[110000];
struct edge2
{
	int u,v,w;
}e2[100002];
int n,m,et,Q;
int first[20000],depth[20000],ans[20000],father[20000],f[20000][20],g[20000][20];
bool p[20000];
inline bool operator < (edge2 lhs,edge2 rhs)
{
	return lhs.w > rhs.w;
}
void add_edge(int x,int y,int w)
{
	e[++et].v = y;
	e[et].w = w;
	e[et].next = first[x];
	first[x] = et;
}
int getfather(int x)
{
	if (father[x] == x)
		return x;
	father[x] = getfather(father[x]);
	return father[x];
}
void dfs(int x)
{
	p[x] = true;
	for (int i = 1;i <= 16;i ++)
	{
		if (depth[x] < (1 << i)) break;
		f[x][i] = f[f[x][i - 1]][i - 1];
		g[x][i] = min(g[x][i - 1],g[f[x][i - 1]][i - 1]);
	}
	for (int i = first[x];i ;i = e[i].next)
		if (!p[e[i].v])
		{
			f[e[i].v][0] = x;
			g[e[i].v][0] = e[i].w;
			depth[e[i].v] = depth[x] + 1;
			dfs(e[i].v);
		}
}
int find(int x,int y)
{
	if (depth[x] < depth[y])
		swap(x,y);
	int res = 1 << 30;
	int i = 16;
	while (depth[y] < depth[x])
	{
		if (depth[x] - depth[y] >= (1 << i))
		{
			res = min(res,g[x][i]);
			x = f[x][i];
		}
		if (i == 0) break;
		i --;
	}
	if (x == y) return res;
	//printf("%d %d\n",depth[x],depth[y]);
	for (int i = 16;i >= 0;i --)
	{
		if (f[x][i] != f[y][i])
		{
			res = min(res,min(g[x][i],g[y][i]));
			x = f[x][i],y = f[y][i];
		}
	}
	res = min(res,min(g[x][0],g[y][0]));
	//printf("%d %d\n",f[x][0],f[y][0]);
	return res;
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i = 1;i <= m;i ++)
		scanf("%d %d %d",&e2[i].u,&e2[i].v,&e2[i].w);
	sort(e2 + 1,e2 + m  + 1);
	for (int i = 1;i <= n;i ++)
		father[i] = i;
	for (int i = 1;i <= m;i ++)
	{
		int x,y; 
		x = getfather(e2[i].u);
		y = getfather(e2[i].v);
		if (x == y) continue;
		father[x] = y;
		//printf("%d %d\n",getfather(x),father[x]);
		add_edge(e2[i].u,e2[i].v,e2[i].w);
		add_edge(e2[i].v,e2[i].u,e2[i].w);		
		//printf("%d %d %d\n",e2[i].u,e2[i].v,e2[i].w);
	}
	memset(g,0x3f,sizeof(g));
	for (int i = 1;i <= n;i ++)
		if (!p[i])
			depth[i] = 1,dfs(i);
	/*for (int i = 1;i <= n;i ++)
	{
		for (int j =0;j <= 16;j ++)
			printf("%d ",f[i][j]);
		cout << endl;
	}*/
	scanf("%d",&Q);
	for (int i = 1;i <= Q;i ++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int fx = getfather(x),fy = getfather(y);
		if (fx != fy)
			printf("-1\n");
		else printf("%d\n",find(x,y));
	}
	fclose(stdin);fclose(stdout);
}