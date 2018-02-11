#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int c[1000001],d[1000001],e[1000001];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,b,i,j,maxn=-99999999;
	scanf("%d%d",&a,&b);
	for(i=0;i<a;i++) 
	{
	   scanf("%d",&c[i]);
	   d[i]=c[i];
	   for(j=0;j<i;j++) d[i]+=c[j];
    }
    e[0]=d[0];
    for(i=1;i<a;i++)
	{
	   e[i]=-9999999;
	   for(j=0;j<i;j++) if(e[j]+d[j]>e[i]) e[i]=e[j]+d[j];
	}
	for(i=0;i<a;i++) if(e[i]>maxn) maxn=e[i];
	if(maxn<0) printf("-");
	maxn=abs(maxn);
	maxn%=b;
	printf("%d\n",maxn);
	return 0;
}
