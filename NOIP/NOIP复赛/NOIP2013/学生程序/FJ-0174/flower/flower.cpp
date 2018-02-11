#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=100010;

class TreeType
{
	public:
		int maxlength,x,y;
}t0[maxn*20],t1[maxn*20];

class ck
{
	public:
		int x,y;
}b[maxn];

int a[maxn];
int f[maxn][2];

int n;

void init()
{
	scanf("%d",&n);
	for  (int i=1;i<=n;i++) scanf("%d",&a[i]);
}

void solve70()
{
	for (int i=1;i<=n;i++) f[i][0]=f[i][1]=1;
	int ans=1;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			if (a[j]<a[i] && f[j][0]+1>f[i][1]) f[i][1]=f[j][0]+1;
			if (a[j]>a[i] && f[j][1]+1>f[i][0]) f[i][0]=f[j][1]+1;
		}
		ans=max(ans,f[i][1]);
		ans=max(ans,f[i][0]);
	}
	printf("%d\n",ans);
}


bool cpr(ck a,ck b)
{
	return a.x<b.x;
}

void build_t1(int k,int x,int y)
{
	t1[k].x=x;
	t1[k].y=y;
	t1[k].maxlength=0;
	if (x==y) return;
	int mid=(x+y)>>1;
	build_t1(2*k,x,mid);
	build_t1(2*k+1,mid+1,y);
}
void build_t0(int k,int x,int y)
{
	t0[k].x=x;
	t0[k].y=y;
	t0[k].maxlength=0;
	if (x==y) return;
	int mid=(x+y)>>1;
	build_t0(2*k,x,mid);
	build_t0(2*k+1,mid+1,y);
}


int find1(int k,int d)
{
	if (t1[k].y<=d) return 0;
	if (t1[k].x>d) return t1[k].maxlength;
	int mid=(t1[k].x+t1[k].y)>>1;
	int ans=find1(k*2+1,d);
	if (mid>d) ans=max(ans,find1(k*2,d));
	return ans;
}
int find0(int k,int d)
{
	if (t0[k].x>=d) return 0;
	if (t0[k].y<d) return t0[k].maxlength;
	int mid=(t0[k].x+t0[k].y)>>1;
	int ans=find0(k*2,d);
	if (mid+1<d) ans=max(ans,find0(2*k+1,d));
	return ans;
}

void renew1(int k,int pos,int d)
{
	if (t1[k].x==t1[k].y)
	{
		t1[k].maxlength=max(t1[k].maxlength,d);
		return;
	}
	int mid=(t1[k].x+t1[k].y)>>1;
	if (pos<=mid) renew1(2*k,pos,d); else renew1(2*k+1,pos,d);
	t1[k].maxlength=max(t1[2*k].maxlength,t1[2*k+1].maxlength);
}
void renew0(int k,int pos,int d)
{
	if (t0[k].x==t0[k].y)
	{
		t0[k].maxlength=max(t0[k].maxlength,d);
		return;
	}
	int mid=(t0[k].x+t0[k].y)>>1;
	if (pos<=mid) renew0(2*k,pos,d); else renew0(2*k+1,pos,d);
	t0[k].maxlength=max(t0[2*k].maxlength,t0[2*k+1].maxlength);
}


void dp()
{
//	for (int i=1;i<=n;i++) printf("%d ",a[i]); printf("\n");
	f[1][1]=f[1][0]=1;
	//printf("--------%d\n",find1(1,a[1]));
	renew1(1,a[1],1);
	renew0(1,a[1],1);
	//printf("--------%d\n",find1(1,a[1]));
	for (int i=2;i<=n;i++)
	{
		int k;
		k=find1(1,a[i]);
	//	if (i==2) printf("---k=%d\n",k);
		f[i][0]=1;
		f[i][0]=max(f[i][0],k+1);
		
		k=find0(1,a[i]);
		//if (i==4) printf("---k=%d\n",k);
		f[i][1]=1;
		f[i][1]=max(f[i][1],k+1);
		//get_f
		
		renew1(1,a[i],f[i][1]);
		renew0(1,a[i],f[i][0]);
	}
}

void solve100()
{
	for (int i=1;i<=n;i++)
	{
		b[i].x=a[i];
		b[i].y=i;
	}
	sort(&b[1],&b[n+1],cpr);
	int k=0;
	b[0].x=-1000;
	for (int i=1;i<=n;i++)
	{
		if (b[i].x!=b[i-1].x) ++k;
		a[b[i].y]=k;
	}///////////////ÀëÉ¢ 
//	printf("max h is:%d\n",k);
	
	//printf("--------%d\n",find1(1,a[1]));
	
	build_t1(1,1,k);
	build_t0(1,1,k);
	
	dp();
	
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		ans=max(ans,f[i][1]);
		ans=max(ans,f[i][0]);
	}
	printf("%d",ans);
}

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	init();
	if (n<=1000)  solve70();  else 
	solve100();
	//for (int i=1;i<=n;i++) printf("f[%d][1]=%d  f[%d][0]=%d\n",i,f[i][1],i,f[i][0]);
	return 0;
}
