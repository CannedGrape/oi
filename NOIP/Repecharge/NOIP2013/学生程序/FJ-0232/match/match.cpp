#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define F(i,j,k) for(i=j;i<=k;i++)
using namespace std;
struct ne
{
	int s,w;
} a1[100001],b1[100001];
int zy(ne a,ne b)
{
	if(a.s<b.s)return 1;
	return 0;
}
int n,i,j,k,l,m,ls,maxn,ji,kk,mm=2147483647;
int a[100001],b[100001];
int wp(int t,int w,int ji)
{
	int i;
	if(t>=w)
	{
		
		if(mm>ji)mm=ji;
		return 0;
	}
	if (ji>=maxn) return 0;
	kk=b[t];b[t]=b[t+1];b[t+1]=kk;
	if(b[t]==a[t])wp(t+1,w,ji+1);
	t--;
	ji--;
	kk=b[t];b[t]=b[t+1];b[t+1]=kk;
	kk=b[w];b[w]=b[w+1];b[w+1]=kk;
	if(b[w]==a[w])wp(t,w+1,ji+1);
	w--;ji--;
	kk=b[w];b[w]=b[w+1];b[w+1]=kk;
	for(i=t;i<w;i++)
	{
		
	    kk=b[i];b[i]=b[i+1];b[i+1]=kk;
		wp(t,w,ji+1);
		ji--;
		kk=b[i];b[i]=b[i+1];b[i+1]=kk;
	}
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n;
	F(i,1,n)scanf("%d",&a[i]);
	F(i,1,n)scanf("%d",&b[i]);
	F(i,1,n)
	{
	  a1[i].s=a[i];
	  b1[i].s=b[i];
	}
	sort(a1+1,a1+n+1,zy);
	sort(b1+1,b1+n+1,zy);
	F(i,1,n)
	{
		b1[i].w=i;
		a1[i].w=i;
	}
	F(i,1,n)
	  F(j,1,n)if(a[i]==a1[j].s){a1[j].w=i;b1[j].w=i;}
	F(i,1,n)
	  F(j,1,n)if(b[i]==b1[j].s)b[i]=b1[j].w;
	ls=n;k=1;
	while(a[k]==b[k])k++;k--;
	while(a[ls]==b[ls])ls--;ls++;
	/*maxn=1;
	for(i=k;i<=ls;i++)maxn=maxn*(i-k+1);
	wp(k,ls,0);*/
	cout<<ls-k;
	return 0;
}
