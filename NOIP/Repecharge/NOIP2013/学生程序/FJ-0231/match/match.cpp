#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,a[100001],b[100001],l,ans;
//int f[1000][1000];
bool cmpa(int x,int y){if(a[x]<a[y]) return 1;else return 0;}
bool cmpb(int x,int y){if(b[x]<b[y]) return 1;else return 0;}
int main()
{
	int t,k,q;
	int c[100001],d[100001];
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {scanf("%d",&a[i]);c[i]=i;} sort(c+1,c+n+1,cmpa);
	for(i=1;i<=n;i++) {scanf("%d",&b[i]);d[i]=i;} sort(d+1,d+n+1,cmpb);
	for(i=1;i<=n;i++) {if(a[i]==b[i]) q++;if(q==n) printf("0\n");} 
	for(i=1;i<=n;i++)
	   for(j=i+1;j<=n;j++)
	   {
			if(a[i]==b[j]) 
			{
			ans+=abs(i-j);
			//for()
		    }
	   }
     //f[i][j]=min(f[i-1][j],f[i-1][j-1]);
	for(j=1;j<=n;j++) l+=(a[j]-b[j])*(a[j]-b[j]);
	ans%=99999997;
	printf("%d",ans);
	return 0;
}
