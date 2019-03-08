#include<iostream>
#include<cstdio>
using namespace std;
int n,h[100001],l,maxn,a[100001],k;
long long ans;
bool f1[100001];
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&h[i]);
	maxn=l=h[1];k=1;
	for(i=2;i<=n;i++) 
	{
		if(h[i]>maxn) 
		{
			maxn=h[i];
			if(a[k]<maxn) a[k]=maxn;
		}
	  else if(h[i]<h[i+1]&&h[i]<h[i-1])
		{
			if(h[i+1]>h[i])	
			{
			  if(h[i]<1) l=h[i];
			  else if(h[i]>=1) {l=h[i];f1[i]=1;}
			  maxn=h[i];k++;
			  }
		    else if(h[i+1]<h[i]);
		}
	}
	for(i=1;i<=k;i++) ans+=a[i];
	for(i=1;i<=n;i++) if(f1[i]==1)ans-=h[i];
	cout<<ans<<endl;	
	return 0;
}
