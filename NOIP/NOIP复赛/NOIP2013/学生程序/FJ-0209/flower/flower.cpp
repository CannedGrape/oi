#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define maxn 100010
using namespace std;
int N;
int A[maxn];
int F[maxn][3];
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	memset(A,0,sizeof(A));
	memset(F,0,sizeof(F));
	scanf("%d",&N);
	int i,j;
	for (i=1;i<=N;i++) scanf("%d",&A[i]);
	for (i=1;i<=N;i++)
	{
		F[i][0]=1;F[i][1]=1;
		for (j=1;j<=N-1;j++)
		{
			if (A[j]>A[i]) F[i][0]=max(F[i][0],F[j][1]+1);
			if (A[j]<A[i]) F[i][1]=max(F[i][1],F[j][0]+1);
	    }
    }
    int ans=0;
    for (i=1;i<=N;i++)
    {
		ans=max(ans,F[i][0]);
		ans=max(ans,F[i][1]);
    }
    printf("%d\n",ans);
}
