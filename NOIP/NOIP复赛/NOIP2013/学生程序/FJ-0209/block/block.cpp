#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define maxn 100010
using namespace std;
struct node
{
	int value,num;
	bool operator <(const node &x1)const
	{
		return value>x1.value;
	}
};
priority_queue <node> P;
int A[100010];
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	memset(A,0,sizeof(A));
    int N,num0=0;
    scanf("%d",&N);
    int i,j,k;
    node X;
    for (i=1;i<=N;i++) 
	{
		scanf("%d",&A[i]);
		if (A[i]!=0)
		{
			X.num=i;
			X.value=A[i];
			P.push(X);
		}
		else num0++;
    }
    int ans=0,L,R;
    while (num0<N)
    {
		//for (i=1;i<=N;i++) printf("%d ",A[i]);printf("\n");
		//system("pause");
		while (A[P.top().num]!=P.top().value) P.pop();
		X=P.top();
		P.pop();
		ans+=X.value;
		L=X.num-1;
		while (L>0&&A[L]) L--;
		R=X.num+1;
		while (R<=N&&A[R]) R++;
		for (i=L+1;i<=R-1;i++)
		{
			A[i]-=X.value;
			if (A[i])
			{
			   node X2;
		       X2.num=i;
		       X2.value=A[i];
		       //printf("(%d %d)\n",X2.num,X2.value);
		       P.push(X2);
		    }
		    else num0++;
	    }
	    //printf("[%d %d]\n",P.top().num,P.top().value);
	}
	printf("%d\n",ans);
    return 0;
}
