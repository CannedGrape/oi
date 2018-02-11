#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
const int C=99999997;
long long cost;
int n,i,la,lb,a[100001],b[100001],pa[100001],pb[100001],tc,taska,taskb;
bool da[100002],db[100002];
int tta[200002],ttb[200002];
void tbinc(int t)
{
	if (t>n) return;
	ttb[t]++;
	tbinc(t+(t&(-t)));
}
void tainc(int t)
{
	if (t>n) return;
	tta[t]++;
	tainc(t+(t&(-t)));
}
int tsb(int t)
{
	if (t<=0) return 0;
	return (ttb[t]+tsb(t-(t&(-t))));
}
int tsa(int t)
{
	if (t<=0) return 0;
	return (tta[t]+tsa(t-(t&(-t))));
}
int askb(int l,int r)
{
	taskb=(r-l)-(tsb(r)-tsb(l));
	return taskb;
}
int aska(int l,int r)
{
	taska=(r-l)-(tsa(r)-tsa(l));
	return taska;
}
void qs1(int l,int r)
{
	int i=l,j=r,x=a[(l+r)/2],y;
    while (i<j)
    {
		while (a[i]<x) i++;
		while (x<a[j]) j--;
		if (i<=j)
		{
        	y=a[i];a[i]=a[j];a[j]=y;
        	y=pa[i];pa[i]=pa[j];pa[j]=y;
        	i++;j--;
		}
	}
    if (l<j) qs1(l,j);
    if (i<r) qs1(i,r);
}
void qs2(int l,int r)
{
	int i=l,j=r,x=b[(l+r)/2],y;
    while (i<j)
    {
		while (b[i]<x) i++;
		while (x<b[j]) j--;
		if (i<=j)
		{
        	y=b[i];b[i]=b[j];b[j]=y;
        	y=pb[i];pb[i]=pb[j];pb[j]=y;
        	i++;j--;
		}
	}
    if (l<j) qs2(l,j);
    if (i<r) qs2(i,r);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++) {scanf("%d",&a[i]);pa[i]=i;}
	for (i=1;i<=n;i++) {scanf("%d",&b[i]);pb[i]=i;}
	qs1(1,n);qs2(1,n);
	for (i=1;i<=n;i++) {a[pa[i]]=i;b[pb[i]]=i;da[i]=0;db[i]=0;}
	da[n+1]=false;db[n+1]=false;
	la=1;lb=1;cost=0;
	for (i=1;i<=n;i++)
	{
		if (a[la]==b[lb])
		{
			da[la]=1;db[lb]=1;
			tainc(la);tbinc(lb);
		}
		else
		{
			if (aska(la,pa[b[lb]])<askb(lb,pb[a[la]]))
			{
				cost+=taska;
				db[lb]=1;da[pa[b[lb]]]=1;
				tainc(pa[b[lb]]);tbinc(lb);
			}
			else
			{
				cost+=taskb;
				da[la]=1;db[pb[a[la]]]=1;
				tbinc(pb[a[la]]);tainc(la);
			}
		}
		while (cost>C) cost-=C;
		while (da[la]) la++;
		while (db[lb]) lb++;
	}
	tc=cost;
	printf("%d\n",tc);
	return 0;
}

