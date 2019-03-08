#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=20010;
class ck
{
	public:
		int x,next,d;
}edge[maxn*10];

class Begin_Edge
{
	public:
		int x,y,d;
}beg_e[maxn*10];

class tree_T
{
	public:
		int x,d;
}f[maxn][20];

bool found[maxn*10];
int d[maxn],father[maxn],q[maxn],dep[maxn],pow[20];

int n,m,tot;

void new_e(int x,int y,int d)
{
	edge[++tot].x=y;
	edge[tot].d=d;
	edge[tot].next=edge[x].next;
	edge[x].next=tot;
}

bool cpr(Begin_Edge a,Begin_Edge b)
{
	return a.d>b.d;
}

void qsort(int x,int y)
{
	int p=x,q=y;
	Begin_Edge t=beg_e[(x+y)>>1];
	while (x<y)
	{
		while (cpr(beg_e[x],t)) ++x;
		while (cpr(t,beg_e[y])) --y;
		if (x<=y)  swap(beg_e[x++],beg_e[y--]);
	}
	if (x<q) qsort(x,q);
	if (p<y) qsort(p,y);
}

void init()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&beg_e[i].x,&beg_e[i].y,&beg_e[i].d);
}

int get_f(int k)
{
	if (father[k]==k) return k;
	father[k]=get_f(father[k]);
	return father[k];
}

void get_tree_edge()
{
	for (int i=1;i<=n;i++) 
	{
		beg_e[m+i].x=i;
		beg_e[m+i].y=n+1;
		beg_e[m+i].d=-1;
	}
	m+=n;
	for (int i=1;i<=n+1;i++) father[i]=i;
	for (int i=1;i<=m;i++) found[i]=0;
	int count=0;
	for (int i=1;i<=m;i++)
	{
		int x=beg_e[i].x,y=beg_e[i].y;
		if (get_f(x)==get_f(y)) continue;
		father[father[x]]=father[y];
		found[i]=1;
		++count;
		if (count==n) break;
	}
//	cout<<count<<endl;
	tot=n+1;
	for (int i=1;i<=m;i++)
		if (found[i])
		{
			new_e(beg_e[i].x,beg_e[i].y,beg_e[i].d);
			new_e(beg_e[i].y,beg_e[i].x,beg_e[i].d);
		}
}

void build_tree()
{
	for (int i=1;i<=n+1;++i) found[i]=0;
	found[n+1]=1;
	int first=1,last=1;
	q[1]=n+1;
	dep[n+1]=1;
	pow[0]=1;
	for (int i=1;i<15;i++) pow[i]=pow[i-1]<<1;
	while (first<=last)
	{
		int k=q[first++];
		for (int i=edge[k].next;i;i=edge[i].next)
		{
			int x=edge[i].x;
			if (!found[x])
			{
				f[x][0].x=k;
				f[x][0].d=edge[i].d;
				dep[x]=dep[k]+1;
				q[++last]=x;
				found[x]=1;
			}
		}
		for (int i=1;i<15;i++)
			if (pow[i]<dep[k])
			{
				f[k][i].x=f[f[k][i-1].x][i-1].x;
				f[k][i].d=min(f[f[k][i-1].x][i-1].d,f[k][i-1].d);
			}
	}
}

void solve()
{
	int trucks;
	scanf("%d",&trucks);
	for (int i=1;i<=trucks;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (dep[x]<dep[y]) swap(x,y);
		int ans=100000000;
		if (dep[x]!=dep[y])
		{
			for (int j=14;j>=0;--j)
				if (dep[x]-pow[j]>=dep[y])
				{
					ans=min(ans,f[x][j].d);
					x=f[x][j].x;
					if (dep[x]==dep[y]) break;
				}
		}////////  Adjust dep
		if (x==y) printf("%d\n",ans);
			else
			{
				for (int j=14;j>=0;--j)
					if (f[x][j].x!=f[y][j].x)
					{
						ans=min(ans,f[x][j].d);
						ans=min(ans,f[y][j].d);
						x=f[x][j].x;
						y=f[y][j].x;
					}
				ans=min(ans,f[x][0].d);
				ans=min(ans,f[y][0].d);
				printf("%d\n",ans);
			}
	}
}

int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	init();
	qsort(1,m);
	get_tree_edge();
	//cout<<m<<"```"<<endl;
	/*for (int i=1;i<=m;i++) 
		if (found[i])
			printf("%d %d %d\n",beg_e[i].x,beg_e[i].y,beg_e[i].d);*/
	build_tree();
/*	for (int i=1;i<=n;i++)
	{
		printf("i=%d:\n",i);
		printf("    ");
		for (int j=0;j<15;j++) if (f[i][j].x) printf("%d ",f[i][j].x); printf("\n");
		printf("    ");
		for (int j=0;j<15;j++) if (f[i][j].x) printf("%d ",f[i][j].d); printf("\n");
	}*/
	solve();
	return 0;
}
