#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxN=100010,maxint=~0U>>1;
int H[maxN]={},to[maxN][4]={},w[maxN][4]={},ansp=-1;
double ans=maxint;
inline void check(const int &s,const int &x0,const bool &t)
{
	register int totA=0,totB=0,now=s;
	register bool flag=true;
	while(true)
	{
		if(flag)
		{
			if(w[now][2]==0 || totA+totB+w[now][2]>x0)
			    break;
			totA+=w[now][2];
			now=to[now][2];
			flag=false;
		}
		else
		{
			if(w[now][1]==0 || totA+totB+w[now][1]>x0)
			    break;
			totB+=w[now][1];
			now=to[now][1];
			flag=true;
		}
	}
	if(t)
	{
    	if(totB==0)
	        totA=maxint,totB=1;
    	if(ansp==-1 || ans>double(totA)/totB || (ans>double(totA)/totB && H[ansp]<H[s]))
	    {
	        ans=double(totA)/totB;
    	    ansp=s;
	    }
	}
	else
	    printf("%d %d\n",totA,totB);
	return;
}
int main()
{
	freopen("drive.in","r",stdin);
	freopen("drive.out","w",stdout);
	register int N=0,M=0,a,b,ta,tb,t,x0,s;
	scanf("%d",&N);
	for(register int i=1;i<=N;++i)
		scanf("%d",H+i);
	for(register int i=1;i<=N;++i)
	{
		a=b=maxint;
		ta=tb=0;
		for(register int j=i+1;j<=N;++j)
		{
			if(N>9000 && j-i>7000)
			    break;
			t=abs(H[i]-H[j]);
			if(t<a || (t==a && H[j]<H[ta]))
			{
				b=a;
				tb=ta;
				a=t;
				ta=j;
			}
			else if(t<b || (t==b && H[j]<H[tb]))
			{
				b=t;
				tb=j;
			}
		}
		if(ta!=0)
		{
		    w[i][1]=a;
		    to[i][1]=ta;
		}
		if(tb!=0)
		{
	    	w[i][2]=b;
    	    to[i][2]=tb;
		}
		if(ta==1 && tb==1)
		    break;
	}
	scanf("%d",&x0);
	for(register int i=1;i<=N;++i)
	    check(i,x0,true);
	printf("%d\n",ansp);
	scanf("%d",&M);
	for(register int i=1;i<=M;++i)
	{
		scanf("%d%d",&s,&x0);
	    check(s,x0,false);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
