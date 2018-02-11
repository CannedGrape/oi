#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int rooms[1100000];
int blocks[11000];  // RMinQ
int blocksm[11000];  // RMinQ
int n,m;
int blocknum;
int tob(int x)
{
	return (x-1)/blocknum+1;
}
bool check(int l,int r,int v)
{
	int bs=tob(l)+1;
	int be=tob(r)-1;
	int rmin=0x3fffffff;
	// printf("! %d %d %d %d %d\n",bs,be,l,r,blocknum);fflush(stdout);
	//printf("modify:");
//	printf("[%d,%d]=[%d,%d]+",l,r,bs*blocknum,be*blocknum);
	for (int i=bs;i<=be;i++) {
	//	printf("%d",i);
		rmin=min(rmin,blocks[i]-blocksm[i]);
		blocksm[i]+=v;
	}

	int fe=min((bs-1)*blocknum,r);
	//printf("[%d,%d]",l,fe);
	//printf("[");
	for (int i=l;i<=fe;i++) 
	{
		int blockid=tob(i);
		//printf("%d",blockid);
		int vi=rooms[i]-blocksm[blockid];
		rmin = min(vi,rmin);
		rooms[i]-=v;
		if (blocks[blockid]>rooms[i]) blocks[blockid] = rooms[i];
	}
	int fs=max(be*blocknum+1,l);
	if (tob(l)!=tob(r))
	{
		//printf("+[%d,%d]\n",fs,r);
		for (int i=fs;i<=r;i++) 
		{
			int blockid=tob(i);
			//printf("%d",blockid);
			int vi=rooms[i]-blocksm[blockid];
			rmin = min(vi,rmin);
			rooms[i]-=v;
			if (blocks[blockid]>rooms[i]) blocks[blockid] = rooms[i];
		}
	}
	//printf("]\n%d %d %d\n",l,r,rmin);
	if (rmin<v) return false;
	return true;
};
int main()
{
	freopen("classroom.in","r",stdin);
	freopen("classroom.out","w",stdout);

	scanf("%d%d",&n,&m);

	blocknum = (int)floor(sqrt((double)n));
	//printf("%d\n",blocknum);
	for (int i=1;i<=blocknum;i++) blocks[i]=0x3fffffff;

	for (int i=1;i<=n;i++) {
//		printf("%d,",(i-1)/blocknum+1);fflush(stdout);
		scanf("%d",&rooms[i]);
		blocks[tob(i)]=min(blocks[tob(i)],rooms[i]);
	}

	for (int i=1;i<=m;i++)
	{
		int d,s,t;
		scanf("%d%d%d",&d,&s,&t);

		if (!check(s,t,d))
		{
			printf("-1\n%d\n",i);return 0;
		}
	}
	printf("0\n");
	return 0;
}
