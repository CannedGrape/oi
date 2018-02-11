#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <deque>
#include <ctime>
using namespace std;
typedef long long LL;
const int Maxn=1000100;
int A[Maxn],N,M,K,x,cnt,flag[Maxn];
int B[Maxn],tot,vis[Maxn];

int Get()
{
	int f=0,v=0; char ch;
	while (!isdigit(ch=getchar())) if (ch=='-') break;
	if (ch=='-') f=1; else v=ch-48;
	while (isdigit(ch=getchar())) v=v*10+ch-48;
	if (f==1) return -v; else return v;
}

void pusu()
{
	int Time=1;
	for (int i=1;i<=K;i++) Time*=10;
	for (int i=1;i<=Time;i++)
	{
		x=(x+M)%N;	
	}
	printf("%d\n",x);
}

void init()
{
	N=Get(); M=Get(); K=Get(); x=Get();
	if (K<=7) {pusu(); exit(0);}
	memset(flag,0,sizeof(flag));
	cnt=0;
	while (flag[x]==0)
	{
		flag[x]=1; A[++cnt]=x;
		x=(x+M)%N;
	}
}

int Pow(int a,int b,int p1)
{
	int res=1;
	for (a%=p1;b>0;b/=2)
	{
		if (b%2==1) res=((LL)res*(LL)a)%p1;
		a=(LL)a*(LL)a%p1;	
	}	
	return res;
}

int main()
{
	freopen("circle.in","r",stdin); freopen("circle.out","w",stdout);
	init();
	int temp=cnt-10%cnt; 
	memset(vis,0,sizeof(vis));
	tot=-1; int t1=temp;
	while (vis[temp]==0)
	{
		vis[temp]=1; B[++tot]=temp;
		temp=(temp+t1)%cnt;
	}
	 printf("%d\n",A[((cnt-B[(Pow(10,K-1,tot+1)+tot)%(tot+1)]+1)%cnt+cnt)%cnt]);
	
	return 0;
}
