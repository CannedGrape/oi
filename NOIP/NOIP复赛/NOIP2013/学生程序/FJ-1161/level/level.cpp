# include<iostream>
# include<cstdio>
# include<cstdlib>
# include<cstring>
# include<string>
# include<cmath>
# include<algorithm>
using namespace std;
long n,m,s[1005],x[1005][1005],f[1005][1005],sum=0;
bool a[1005];

int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	
	long i,j;
	scanf("%d%d",&n,&m);
	for (i=0;i<m;i++) 
	{
		 scanf("%d",&s[i]);
		 for (j=0;j<n;j++) a[j]=0;
		 for (j=0;j<s[i];j++) scanf("%d",&x[i][j]),a[x[i][j]]=1;
		 for (j=0;j<x[i][0];j++) f[i][j]=f[i-1][j];
		 for (j=x[i][0]+1;j<x[i][s[i]-1];j++)
		 {
			  if (a[j]==0)
			  {
			       if (a[j-1]==1) f[i][j]=f[i][j-1]+1;
			       if (a[j-1]==0) f[i][j]=f[i-1][j]+f[i][j-1];
			  }
			  if (a[j]==1)
			  {
			       if (a[j-1]==1) f[i][j]=f[i][j-1];
			       if (a[j-1]==0) f[i][j]=f[i][j-1]-1;
			  }
		 }
	}
	for (i=0;i<n;i++) if (f[m-1][i]>sum) sum++;
	printf("%d\n",sum+1);
	
	return 0;
}
