#include<iostream> 
#include<cstdio>
#include<cstdlib>

using namespace std;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
    int n,x,a[10]={0};
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
    {   int t=i;
        while(t>0){++a[t-t/10*10];t/=10;}
	}
	printf("%d\n",a[x]);
return 0;
}
