#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int n,x,ans,i,j,k,l;

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++)
	{l=i;
		while(l!=0)
		{k=l%10;l/=10;if(k==x)ans++;}
	}
	printf("%d\n",ans);
	return 0;
}

