# include<iostream>
# include<cstdio>
# include<cstdlib>
# include<cstring>
# include<string>
# include<cmath>
# include<algorithm>
using namespace std;
long n,x,f[10];

int main()
{
	freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
	
	long i,k;
	scanf("%d%d",&n,&x);
	for (i=1;i<=n;i++) 
	{
		 k=i;
		 for (;k>=10;) f[k%10]++,k/=10;
		 f[k]++;
	}
	printf("%d\n",f[x]);
	
	return 0;
}
