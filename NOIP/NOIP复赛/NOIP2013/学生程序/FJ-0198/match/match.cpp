#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<queue>

using namespace std;

const int Maxn=100010;
const int mo=99999997;

int n,ans=0;
int pos[Maxn];

struct Match
{
	int h,p;
}a[Maxn],b[Maxn];

bool cmp(Match x,Match y){return x.h<y.h;}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	scanf(" %d",&n);
	for(int i=1;i<=n;i++) scanf(" %d",&a[i].h),a[i].p=i;
	for(int i=1;i<=n;i++) scanf(" %d",&b[i].h),b[i].p=i;
	
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	
	for(int i=1;i<=n;i++) pos[a[i].p]=i;
	//for(int i=1;i<=n;i++) printf("%d ",pos[i]);
	
	for(int i=1;i<=n;i++)
	{
		if(a[i].p==b[i].p) continue;
		ans++; ans%=mo;
		Match ta=a[i],tb=b[i];
		swap(a[i],a[pos[b[i].p]]);
		swap(pos[ta.p],pos[tb.p]);
	}
	
	printf("%d\n",ans);
	
	//system("pause");
	return 0;
}

