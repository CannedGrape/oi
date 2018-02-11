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
const int Mod=99999997,Maxn=100100;
int N,A[Maxn],B[Maxn],T1[Maxn],T2[Maxn],Pos[Maxn],Map[Maxn],C[Maxn],lazy[Maxn];

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
	for (int i=1;i<=N;i++) A[i]=T1[i]=Get(),Pos[A[i]]=i;
	for (int i=1;i<=N;i++) B[i]=T2[i]=Get();
	sort(T1+1,T1+N+1); sort(T2+1,T2+N+1);
	for (int i=1;i<=N;i++) Map[T2[i]]=T1[i];
}

/*void add(int x,int v)
{
	for (;x<=N;x+=(x&-x)) C[x]+=v;	
}

int getsum(int x)
{
	int res=0;
	for (;x>=1;x-=(x&-x)) res+=C[x];
	return res;
}*/

/*int getlazy(int x)
{
	if (getsum(x)==0) return getsum(x);	
	return getsum(x)+getlazy(x+getsum(x));
}*/

int main()
{
	freopen("match.in","r",stdin); freopen("match.out","w",stdout);
	init();
	int ans=0,temp;
	for (int i=1;i<=N;i++)
	{
		for (int j=i;j<=N;j++) if (A[j]==Map[B[i]]) {temp=j; break;}
		ans=(ans+temp-i)%Mod;
		for (int j=temp;j>=i+1;j--) A[j]=A[j-1]; 
	}
	printf("%d\n",ans);
	return 0;
}
