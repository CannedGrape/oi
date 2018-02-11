#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const int qumod=99999997;
int n,tot;
struct orz
{
	int a,b;
} x[100005];
int tmp[100005];

bool cmp(orz u,orz v)
{
	return u.b<v.b;
}

void merge_sort(int l,int r)
{
	if (r==l || r-l==1) return;
	int mid=(l+r)/2;
	merge_sort(l,mid);
	merge_sort(mid,r);
	int i=l,j=mid,p=l,k;
	while (i<mid || j<r)
	{
		if (j==r || (i<mid && x[i].a<x[j].a)) tmp[p]=x[i++].a;
		else 
		{	
			tmp[p]=x[j++].a;
			tot=(tot+mid-i)%qumod;
		}
		++p;
	}
	for (k=l;k<r;++k) x[k].a=tmp[k];
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int i;
	scanf("%d",&n);
	for (i=0;i<n;++i) scanf("%d",&x[i].a);
	for (i=0;i<n;++i) scanf("%d",&x[i].b);
	sort(x,x+n,cmp);
	tot=0;
	merge_sort(0,n);
	printf("%d\n",tot);
	return 0;
}

