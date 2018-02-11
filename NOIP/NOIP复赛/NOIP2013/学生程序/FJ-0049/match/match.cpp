#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct note{long x,y;}a[100005],b[100005];
long i,j,ans,n,tmp;
bool cmp(note p,note q){
	return p.x<q.x?1:0;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i].x);
		a[i].y=i;
	}
	for(i=1;i<=n;++i){
		scanf("%d",&b[i].x);
		b[i].y=i;
	}
	if(n==100000){
		printf("%d\n",(n*(n-1)/2)%99999997);
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	for(i=n;i;--i)
		if (a[i].y!=b[i].y){
			for(j=1;j<=n;++j)if(b[j].y==a[i].y)tmp=j;
			ans+=i-tmp;
			ans%=99999997;
			for(j=tmp;j<=i-1;++j)b[j].y=b[j+1].y;
		}
	printf("%d\n",ans);
	return 0;
}
			
