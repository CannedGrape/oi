#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define MAXN 1000
#define INF 10000000

int N,a[1000],b[1000],F[1000];

void init()
{
	cin>>N;
	for(int i=1;i<=N;i++)cin>>a[i];
	for(int i=1;i<=N;i++)cin>>b[i];
}

inline int fun(int a1,int b1,int a2,int b2)
{
	return (a1-b1)*(a1-b1)+(a2-b2)*(a2-b2);
}

void P()
{
	int ans=0;
	for(int i=2;i<=N;i++)
	{
		if( ((a[i-1]-b[i-1])*(a[i-1]-b[i-1])+(a[i]-b[i])*(a[i]-b[i]))>((a[i-1]-b[i])*(a[i-1]-b[i])+(a[i]-b[i-1])*(a[i]-b[i-1])) )
		{
			swap(a[i],a[i-1]);
			ans++;
		}
	}
	cout<<ans<<endl;
}

void DP()
{
	F[0]=0;
	for(int i=1;i<=N;i++)
	{
		int ansi=i,anssum=INF;
		for(int j=1;j<i;j++)
		{
			if(fun(a[i],b[i],a[j],b[j])>fun(a[j],b[i],a[i],b[j]))
			{
				if(fun(a[j],b[i],a[i],b[j])<anssum)
				{
					anssum=fun(a[j],b[i],a[i],b[j]);
					ansi=j;
				}
			}
		}
		swap(a[i],a[ansi]);
		if(ansi==i)F[i]=F[i-1];
			else F[i]=F[i-1]+2*(i-ansi)-1;
	}
	/*for(int i=1;i<=N;i++)cout<<F[i]<<' ';
		cout<<endl;*/
	cout<<F[N]<<endl;
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	init();
	if(N==1){cout<<0<<endl;exit(0);}
	if(N==2)
	{
		if(fun(a[1],b[1],a[2],b[2])>fun(a[2],b[1],a[1],b[2]))cout<<1<<endl;
			else cout<<0<<endl;
		exit(0);
	}
	if(N==3){P();exit(0);}
	DP();
	return 0;
}
	

	