#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct node
{
	int x,y,I,ans;
	bool operator<(const node a1)const{return a1.I>I;}
};
struct node Q[30001];
int n,m,q,p,h[10001]={0},to[50001],next[50001],lim[50001],f[10001],M[10001],Line[100001];
int get(int x,int y)
{
	int k=h[x];
	while(k!=0)
	{
		if(to[k]==y)return k;
		k=next[k];
	}
	return -1;
}
int getf(int k)
{
	if(f[k]==k)return k;
	f[k]=getf(f[k]);
	return f[k];
}
void qqsort(int l,int r)
{
	int i=l,j=r,a=Q[(l+r)/2].x;
	struct node z;
	do
	{
		while(Q[i].x<a)i++;
		while(Q[j].x>a)j--;
		if(i<=j)
		{
			z=Q[i];Q[i]=Q[j];Q[j]=z;
			i++;j--;
		}
	}
	while(i<=j);
	if(i<r)qqsort(i,r);
	if(l<j)qqsort(l,j);
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	p=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,z,k;
		cin>>x>>y>>z;
		k=get(x,y);
		if(k==-1)
		{
			p++;
			to[p]=y;next[p]=h[x];h[x]=p;lim[p]=z;
			p++;
			to[p]=x;next[p]=h[y];h[y]=p;lim[p]=z;
			f[getf(x)]=getf(y);
		}
		else
		{
			lim[k]=max(lim[k],z);
			k=get(y,x);
			lim[k]=max(lim[k],z);
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>Q[i].x>>Q[i].y;
		Q[i].I=i;
	}
	qqsort(1,q);
	Q[0].x=-1;
	for(int i=1;i<=q;i++)
	{
		if(getf(Q[i].x)!=getf(Q[i].y)){Q[i].ans=-1;continue;}
		if(Q[i].x==Q[i-1].x){Q[i].ans=M[Q[i].y];continue;}
		int head=1,tail=1;
		Line[1]=Q[i].x;
		memset(M,0,sizeof(M));
		M[Q[i].x]=2147483647;
		while(head<=tail)
		{
			int x=Line[head];
			head++;
			int k=h[x];
			while(k!=0)
			{
				int a=min(M[x],lim[k]);
				if(M[to[k]]<a)
				{M[to[k]]=a;tail++;Line[tail]=to[k];}
				k=next[k];
			}
		}
		Q[i].ans=M[Q[i].y];
	}
	sort(Q+1,Q+1+q);
	for(int i=1;i<=q;i++)cout<<Q[i].ans<<endl;
	return 0;
}

