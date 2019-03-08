#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,x,i,res=0,a;scanf("%d%d",&n,&x);
	for (i=0;i<=n;i++) {a=i;if (a==0&&a==x) res++;while (a>0) {if (a%10==x) res++;a/=10;}}
	printf("%d\n",res);
	return 0;
}
