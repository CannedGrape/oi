#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
const int K=90000;
int n,m,q,i,j,b[50002][3],p[30002],c[30002][2],f[10001];
int l[100001],r[100001],ll[100001],rr[100001],s[30001],np;
void gf(int t)
{
	if (f[t]==t) return;
	gf(f[t]);
	f[t]=f[f[t]];
}
void tqs(int l,int r)
{
	int i=l,j=r,x=b[(l+r)/2][0],y;
    while (i<j)
    {
		while (b[i][0]>x) i++;
		while (x>b[j][0]) j--;
		if (i<=j)
		{
        	y=b[i][0];b[i][0]=b[j][0];b[j][0]=y;
        	y=b[i][1];b[i][1]=b[j][1];b[j][1]=y;
        	y=b[i][2];b[i][2]=b[j][2];b[j][2]=y;
        	i++;j--;
		}
	}
    if (l<j) tqs(l,j);
    if (i<r) tqs(i,r);
}
void up(int tp)
{
	int ti;
	if (tp>=np)
		for (ti=np+1;ti<=tp;ti++)
		{
			gf(b[ti][1]);gf(b[ti][2]);
			f[f[b[ti][1]]]=f[b[ti][2]];
		}
	else
	{
		for (ti=1;ti<=n;ti++) f[ti]=ti;
		for (ti=1;ti<=tp;ti++)
		{
			gf(b[ti][1]);gf(b[ti][2]);
			f[f[b[ti][1]]]=f[b[ti][2]];
		}
	}
	np=tp;
}
bool lik(int t1,int t2)
{
	gf(t1);gf(t2);
	return (f[t1]==f[t2]);
}
void qs()
{
	int tn=1,i,j,y,mid,t=1;
	l[1]=1;r[1]=q;ll[1]=0;rr[1]=m+1;
	while (t!=tn+1)
	{
		i=l[t],j=r[t],mid=(ll[t]+rr[t])/2;
		up(mid);
		while (i<j)
  		{
			while ((i<=r[t]) && lik(c[i][0],c[i][1])) i++;
			while ((j>=l[t]) && (!lik(c[j][0],c[j][1]))) j--;
			if ((i<=j)&&(i<=r[t])&&(j>=l[t]))
			{
				y=c[i][0];c[i][0]=c[j][0];c[j][0]=y;
				y=c[i][1];c[i][1]=c[j][1];c[j][1]=y;
        		y=p[i];p[i]=p[j];p[j]=y;
				i++;j--;
			}
		}
		if ((l[t]<j)&&(ll[t]<mid))
		{
			tn++;if (tn>K) tn-=K;
			l[tn]=l[t];r[tn]=j;
			ll[tn]=ll[t];rr[tn]=mid;
		}
		if ((i<r[t])&&(mid+1<rr[t]))
		{
			tn++;if (tn>K) tn-=K;
			l[tn]=i;r[tn]=r[t];
			ll[tn]=mid+1;rr[tn]=rr[t];
		}
		t++;if (t>K) t-=K;
	}
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
		scanf("%d%d%d",&b[i][1],&b[i][2],&b[i][0]);
	tqs(1,m);b[m+1][0]=-1;
	scanf("%d",&q);
	for (i=1;i<=q;i++)
	{
		scanf("%d%d",&c[i][0],&c[i][1]);
		p[i]=i;
	}
	for (i=1;i<=n;i++) f[i]=i;
	np=0;qs();
	j=1;
	for (i=1;i<=m;i++)
	{
		up(i);
		while ((j<=q)&&(lik(c[j][0],c[j][1])))
		{
			s[p[j]]=b[i][0];
			j++;
		}
	}
	for (i=j;i<=q;i++) s[p[i]]=-1;
	for (i=1;i<=q;i++) printf("%d\n",s[i]);
	return 0;
}

