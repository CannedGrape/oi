#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
int shu[10];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,m,o=1,x,s=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		o=1;
		x=i;
		while(x>0) 
		{
			shu[o]=x%10;
			x/=10;
			o++;
		}
		for(int j=1;j<o;j++) 
		{
		    if (shu[j]==m) 
		    s++;
		    shu[j]=0;
		}
	}
	printf("%d\n",s);
	return 0;
}
