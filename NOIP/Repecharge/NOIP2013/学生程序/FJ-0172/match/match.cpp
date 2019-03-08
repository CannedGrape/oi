#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
const int Maxn=100002,mod=99999997;
int n,t[Maxn],x[Maxn];
int cnt=0;
struct data{
	int x,pos;
}a[Maxn],b[Maxn];
bool cmp(data a,data b) {return a.x<b.x;}
int get()
{
	int f=0,v=0;char ch;
	while (!isdigit(ch=getchar())) if (ch=='-') break;
	if (ch=='-') f=1;else v=ch-48;
	while (isdigit(ch=getchar())) v=v*10+ch-48;
	if (f) return -v;else return v;
}
void Bsort(int l,int r)
{
	if (l==r) return;
	int mid=(l+r)>>1;
	Bsort(l,mid);Bsort(mid+1,r);
	int l1=l,l2=mid+1,tot=l;
	while (l1<=mid&&l2<=r)
	{
		if (x[l1]<x[l2]) t[tot++]=x[l1++];
		else 
		{
			t[tot++]=x[l2++];
			cnt=(cnt+mid-l1+1)%mod;
		}
	}
	while (l1<=mid) t[tot++]=x[l1++];
	while (l2<=r) t[tot++]=x[l2++];
	for (int i=l;i<=r;i++) x[i]=t[i];
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	n=get();
	for (int i=1;i<=n;i++) a[i].x=get(),a[i].pos=i;
	for (int i=1;i<=n;i++) b[i].x=get(),b[i].pos=i;
	sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++) x[a[i].pos]=b[i].pos;
	cnt=0;Bsort(1,n);
	printf("%d\n",cnt);
	return 0;
}
