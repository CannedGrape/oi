#include<iostream> 
#include<cstdio>
#include<cstdlib>
using namespace std;

int n,m,a[1001],s,z[1001],jl[1001][1001],dj[1001],k=1;

int pd(int k,int s)
{
	if(k==1)return 1;
    int l=1,r=n;
	while(jl[k][l]==0)++l;
	while(jl[k][r]==0)--r;
    if(r-l+1==s)return k-1;
	for(int i=1;i<k;++i)
	{   int bj=0;
	    for(int j=l;j<=r;++j)if(jl[i][j]!=jl[k][j]){bj=-1;break;}
	    if(bj==-1)return k;
	}
	return k-1;
}
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i,++k)
	{   scanf("%d",&s);
	    for(int j=1,t;j<=s;++j){scanf("%d",&t);jl[k][t]=1;}
		if(s==n)k--;
		else k=pd(k,s);
	}
	k--;
	for(int i=1;i<=k;++i)
	{   int d=0,l=1,r=n;
	    while(jl[i][l]==0)++l;
	    while(jl[i][r]==0)--r;
		for(int j=l;j<=r;++j)d=max(d,dj[j]);
		for(int j=l;j<=r;++j)
		    if(jl[i][j])dj[j]=d+1;
	}
	int d=0;
	for(int i=1;i<=n;i++)d=max(d,dj[i]);
	printf("%d\n",d+1);
return 0;
}
