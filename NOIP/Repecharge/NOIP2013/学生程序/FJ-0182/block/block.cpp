#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct node
{
	long h,I;
	bool operator<(const node a1)const{return a1.h<h;}
};
struct node a[100010];
long n,b[100010];
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%ld",&n);
	for(int i=1;i<=n;i++){scanf("%ld",&a[i].h);a[i].I=i;b[i]=a[i].h;}
	sort(a+1,a+n+1);
	long ans=0;
	b[0]=0;b[n+1]=0;
	for(int i=1;i<=n;i++)
	{
		if(b[a[i].I]==0)continue;
		long k=a[i].I,j=b[k];
		ans+=b[k];
		while(b[k-1]!=0)
		{
			k--;
			if(b[k]<j)j=b[k];
			b[k]-=j;
		}
		k=a[i].I;
		j=b[k];
		while(b[k+1]!=0)
		{
			k++;
			if(b[k]<j)j=b[k];
			b[k]-=j;
		}
		b[a[i].I]=0;
	}
	cout<<ans<<endl;
	return 0;
}

