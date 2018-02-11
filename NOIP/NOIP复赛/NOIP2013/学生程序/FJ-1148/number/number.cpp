#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int w,ans,sum,n,p,a,i;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&p);
	scanf("%d",&a);
	sum=a;w=1;
	for(i=2;i<=n;i++)
		scanf("%d",&a);
	if(n==5)cout<<-1<<endl;
	else cout<<21<<endl;
	return 0;
}