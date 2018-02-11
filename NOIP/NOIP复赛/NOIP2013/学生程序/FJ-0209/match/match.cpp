#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#define maxn 100010
#define P 99999997
using namespace std;
int N;
struct node
{
	 int no,value;
};
node a[maxn];
node b[maxn];
int a1[maxn];
int b1[maxn];
int e[maxn];
bool cmp(node x1,node x2)
{
	return x1.value<x2.value;
}
int ni[maxn];
int ans=0,zs=0;
void erfen(int L,int R)
{
	int mid=(L+R)/2;
	if (L<R) 
	{
	  erfen(L,mid); 
	  erfen(mid+1,R);
    }
    if (L==R) return;
    int n1=(mid-L+1),n2=(R-mid);
    int i=1,j=1,x=1;
    while (x<=R-L+1)
    {
		//printf("[%d %d %d]",x,i,j);
		if (i<=n1&&j<=n2)
		{
			if (b1[i+L-1]<=b1[j+mid]) 
			{
				ans=(((n1-i+1)%P)*(zs%P)+(ans%P))%P;
				zs=0;
				ni[x]=b1[i+L-1];
				i++;
		    }
			else 
			{
				ni[x]=b1[j+mid];
				zs++;
				j++;
		    }
	    }
	    else
	    if (i<=n1&&j>n2)
	    {
			ans+=(n1-i+1*zs);
			zs=0;
			ni[x]=b1[i+L-1];
			i++;
	    }
	    else  
		if (i>n1&&j<=n2)
		{
				ni[x]=b1[j+mid];
				zs++;
				j++;
		}
		x++;
    }
    for (i=1;i<=R-L+1;i++) b1[L+i-1]=ni[i];
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&N);
	int i,j,k;
	for (i=1;i<=N;i++) {scanf("%d",&a[i].value);a[i].no=i;}
	for (i=1;i<=N;i++) {scanf("%d",&b[i].value);b[i].no=i;}
	sort(a+1,a+1+N,cmp);
	for (i=1;i<=N;i++) a1[a[i].no]=i;
	sort(b+1,b+1+N,cmp);
	for (i=1;i<=N;i++) b1[b[i].no]=i;
    for (i=1;i<=N;i++) e[a1[i]]=i;
    for (i=1;i<=N;i++) b1[i]=e[b1[i]];
    //for (i=1;i<=N;i++) scanf("%d",&b1[i]);
    erfen(1,N);
    printf("%d\n",ans);
	//for (i=1;i<=N;i++) printf("%d ",b1[i]);
	//printf("[%d]\n",ans);
	return 0;
}
