#include <cstdio>
#include <algorithm>

using namespace std;

struct roadStr
{
	int last,to;
	int maxS;
};


struct numberPair
{
	int key;
	int w;
};


roadStr road[200000];
int roadN;
int tail[10001];
int n,m,q;
int qs[30001],qe[30001],ans[30001];
numberPair np[30001];
int d[10001],b[3000000];
bool in[10001];



void addARoad(int s1,int s2,int s3)
{
	roadN++;
	road[roadN].last=tail[s1];
	tail[s1]=roadN;
	road[roadN].to=s2;
	road[roadN].maxS=s3;
}


bool cmp(numberPair a,numberPair b)
{
	if (a.key<b.key) return(true);
	return(false);
}


void spfa(int start)
{
	int l=1,r=1;
	b[l]=start;
	for (int i=1;i<=n;i++)
	{
		d[i]=-1;
		in[i]=false;
	}
	d[start]=1000000000;
	in[start]=true;
	for (;l<=r;l++)
	{
		for (int k=tail[b[l]];k!=0;k=road[k].last)
		{
			if (min(d[b[l]],road[k].maxS)>d[road[k].to])
			{
				d[road[k].to]=min(d[b[l]],road[k].maxS);
				
				if (!in[road[k].to])
				{
					in[road[k].to]=true;
					r++;
					b[r]=road[k].to;
				}
			}
		}
		in[b[l]]=false;
	}
}


int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int s1,s2,s3;
		scanf("%d%d%d",&s1,&s2,&s3);
		addARoad(s1,s2,s3);
		addARoad(s2,s1,s3);
	}
	
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&qs[i],&qe[i]);
		np[i].key=qs[i];
		np[i].w=i;
	}
	sort(np+1,np+q+1,cmp);
	
	
	np[0].key=0;
	for (int i=1;i<=q;i++)
	{
		if (np[i].key!=np[i-1].key) spfa(np[i].key);
		ans[np[i].w]=d[qe[np[i].w]];
	}
	
	
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	
	return(0);
}

