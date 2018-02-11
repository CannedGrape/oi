#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,q;
int x[50001],y[50001],z[50001];
int a[30001],b[30001];
int ans[30001],temp;
bool f[30001];
int main()
{
	int i,j,t;
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) 
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		if(x[i]>y[i]){temp=x[i];x[i]=y[i];y[i]=temp;}
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{scanf("%d%d",&a[i],&b[i]);ans[i]=3;}
	
	

     for(i=1;i<=m;i++)
	    for (j=1;j<=m;j++)     //f[i][j]=max(f[i-1][j],f[i-1][j-1]+z[i]);	  
	    {
				if(a[i]==x[j])
				{  for(t=1;t<=m;t++)
					
					if(b[i]==y[j])
					
					ans[i]=z[i]<z[j]?z[i]:z[j];
					f[i]==1;
				}
				
				else if(a[i]==y[j])
				{if(b[i]==x[j])
					
					ans[i]=z[i]<z[j]?z[i]:z[j];
					f[i]==1;}
		
	    }
	for(i=1;i<=q;i++)
	{ 
		if(f[i]==1)printf("%d\n",ans[i]);
		else printf("-1\n");
	}
	return 0;
}
