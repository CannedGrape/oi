#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <ctime>
using namespace std;
typedef long long LL;
const int Maxn=100100;
int N,A[Maxn];

int Get()
{
	int f=0,v=0; char ch;
	while (!isdigit(ch=getchar())) if (ch=='-') break;
	if (ch=='-') f=1; else v=ch-48;
	while (isdigit(ch=getchar())) v=v*10+ch-48;
	if (f==1) return -v; else return v;	
}

void init()
{
	N=Get();
	for (int i=1;i<=N;i++) A[i]=Get();
}

int main()
{
	freopen("block.in","r",stdin); freopen("block.out","w",stdout);
	init();
	int i=1,ans=0;
	while (i<=N)
	{
		int j,minn=A[i];
		for (j=i;A[j+1]>0;j++) minn=min(minn,A[j]);
		for (int k=i;k<=j;k++) A[k]-=minn;
		ans+=minn;
		while (A[i]==0 && i<=N) i++;
	}
	printf("%d\n",ans);
	return 0;	
}
