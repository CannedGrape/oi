#include <cstdio>
#include <algorithm>

using namespace std;

struct numberPair
{
	int key;
	int w;
};


struct treeSta
{
	int l,r;
	int w;
	int sum;
	int been;
};


int n;
int a[100001],b[100001];
numberPair np[100001];
int link[100001];
int tree[5000001];


bool cmp(numberPair a,numberPair b)
{
	if (a.key<b.key) return(true);
	return(false);
}


treeSta sta[1000];
int getSum(int lt,int rt)
{
	if (lt>rt) return(0);
	
	int l=1,r=n;
	int top=1;
	sta[top].l=l;
	sta[top].r=r;
	sta[top].w=1;
	sta[top].sum=0;
	sta[top].been=0;
	
	for (;top>0;)
	{
		if (sta[top].l>=lt && sta[top].r<=rt)
		{
			sta[top].sum=tree[sta[top].w];
			top--;
			continue;
		}
		
		if (sta[top].l>rt || sta[top].r<lt)
		{
			sta[top].sum=0;
			top--;
			continue;
		}
		
		int mid=(sta[top].l+sta[top].r)/2;
		l=sta[top].l; r=sta[top].r;
		if (sta[top].been==0)
		{
			sta[top].been=1;
			int jc=sta[top].w;
			top++;
			sta[top].l=l;
			sta[top].r=mid;
			sta[top].w=jc*2;
			sta[top].sum=0;
			sta[top].been=0;
		}
		if (sta[top].been==1)
		{
			sta[top].sum+=sta[top+1].sum;
			sta[top].been=2;
			int jc=sta[top].w;
			top++;
			sta[top].l=mid+1;
			sta[top].r=r;
			sta[top].w=jc*2+1;
			sta[top].sum=0;
			sta[top].been=0;
		}
		if (sta[top].been==2)
		{
			sta[top].sum+=sta[top+1].sum;
			top--;
		}
	}
	
	return(sta[1].sum);
}



void addANumber(int s)
{
	int l=1,r=n;
	int p=1;
	for (;;)
	{
		tree[p]++;
		if (l==r) break;
		int mid=(l+r)/2;
		if (s<=mid) 
		{
			r=mid;
			p=p*2;
		}
		else
		{
			l=mid+1;
			p=p*2+1;
		}
	}
}



int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		np[i].key=a[i];
		np[i].w=i;
	}
	sort(np+1,np+n+1,cmp);
	
	for (int i=1;i<=n;i++)
	{
		a[np[i].w]=i;
		link[i]=np[i].w;
	}
	
		
	
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		np[i].key=b[i];
		np[i].w=i;
	}
	sort(np+1,np+n+1,cmp);
	
	for (int i=1;i<=n;i++)
	{
		b[np[i].w]=link[i];
	}
	
	
	
	//for (int i=1;i<=n;i++) printf("%d ",b[i]); printf("\n");
	
	//ÇóÄæĞò¶Ô 
	int gs=0;
	for (int i=1;i<=n;i++)
	{
		int s=getSum(1,b[i]-1);
		gs+=(b[i]-1-s);
		gs%=99999997;
		addANumber(b[i]);
	}
	
	printf("%d\n",gs);
	
	return(0);
}

