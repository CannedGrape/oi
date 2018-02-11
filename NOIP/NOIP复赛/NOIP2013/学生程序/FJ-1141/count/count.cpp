#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n,x,t,s;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int i;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++)
	{
		t=i;
		while(t!=0)
		{
			if(t%10==x)
			{
				s++;
			}
			t/=10;
		}
	}
	printf("%d\n",s);
	return 0;
}
