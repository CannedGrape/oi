#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
struct node
{
	int l,r,num,poss;
} t[100001];
int a[100001][2];
int i,j,k,l,m,n,p,x,y,z,anss,ttmp;
void buildtree(int l,int r,int poss)
{
	t[poss].l=l;
	t[poss].r=r;
	int mid=(l+r)/2;
	if (r-l>1)
	{
		buildtree(l,mid,poss*2);
		buildtree(mid,r,poss*2+1);
	}
}
void domin(int l,int r,int poss)
{
	if (r-l>1)
	{
		domin(l,(l+r)/2,poss*2);
		domin((l+r)/2,r,poss*2+1);
		if (t[poss*2].num<t[poss*2+1].num) {t[poss].num=t[poss*2].num; t[poss].poss=t[poss*2].poss;}
		else
		{
		t[poss].num=min(t[poss*2].num,t[poss*2+1].num);
		t[poss].poss=t[poss*2+1].poss;
	}
	}
	else
	{
		t[poss].num=a[l][0];
		t[poss].poss=l;
	}
}
int cha(int l,int r,int poss,int minnn)
{
	if ((l==t[poss].l)&&(r==t[poss].r)){if (t[poss].num<minnn){minnn=t[poss].num; ttmp=t[poss].poss;}; return (t[poss].num);};
	int mid=(t[poss].l+t[poss].r)/2;
	if (l>=mid){return cha(l,r,poss*2+1,minnn);} else
	if (r<=mid){return cha(l,r,poss*2,minnn);} else
	return min(cha(l,mid,poss*2,minnn),cha(mid,r,poss*2+1,minnn));
}
void ef(int l,int r,int qian)
{
	if (r<l) return;
	ttmp=0;
	int minn=cha(l,r+1,1,200000000);
	int i,j,k;

	anss+=(minn-qian);
	int asdf;
	for (int i=l; i<=r; i++) if (a[i][0]==minn) {asdf=i; break;};
	if (r-l>=1)
	{
	ef(l,asdf-1,minn);
	ef(asdf+1,r,minn);
    }
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	for (i=1; i<=n; i++) {scanf("%d",&a[i][0]);};
	buildtree(1,n+1,1);
	domin(1,n+1,1);
	anss=0;
	ef(1,n,0);
	printf("%d\n",anss);
	return 0;
}
	
