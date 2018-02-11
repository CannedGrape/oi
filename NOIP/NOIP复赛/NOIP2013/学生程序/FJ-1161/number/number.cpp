# include<iostream>
# include<cstdio>
# include<cstdlib>
# include<cstring>
# include<string>
# include<cmath>
# include<algorithm>
using namespace std;
long n,p,s[1000005];
long f[1000005],x[1000005],sum,k=0;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	long i;
	scanf("%d%d",&n,&p);
	for (i=0;i<n;i++) scanf("%d",&s[i]),f[i]=s[i],x[i]=-2147483647;
	for (i=1;i<n;i++) f[i]=max(f[i-1]+s[i],f[i]);
	sum=x[0]=f[0];
	for (i=1;i<n;i++) 
	{
		 x[i]=max(sum+f[k],x[i]);
		 if (x[i]>sum) sum=x[i],k=i;
	}
	printf("%d\n",sum%p);
		
	return 0;
}
