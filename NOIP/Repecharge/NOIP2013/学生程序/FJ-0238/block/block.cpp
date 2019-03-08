#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int h[100001]={};
int n,sum=0;
void bsearch(int l,int r,int k)
{
	int min_h=10001,min_i;
	for(int i=l;i<=r;i++)
	{
		h[i]-=k;
		if(h[i]<=min_h){min_h=h[i];min_i=i;}
	}
	sum+=min_h;
	if(l<min_i) bsearch(l,min_i-1,min_h);
	if(min_i<r) bsearch(min_i+1,r,min_h);
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>h[i];
	bsearch(1,n,0);
	cout<<sum;
	return 0;
}
