#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
    int num,bh;
}Max_gold;
int n,p;
int a[1000001],good[1000001],gold[1000001];
int main()
{
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    good[1]=a[1];
	for(int i=2;i<=n;i++)
    {
	  good[i]=a[i];
	  if(good[i-1]>0)good[i]+=good[i-1];
	}
	gold[1]=good[1];
	Max_gold.num=gold[1];
	Max_gold.bh=1;
	for(int i=2;i<=n;i++)
	{
	  gold[i]=Max_gold.num+good[Max_gold.bh];
	  if(gold[i]>Max_gold.num)
	  {
	    Max_gold.num=gold[i];
	    Max_gold.bh=i;
	  }
	}
    if(Max_gold.num>=0)Max_gold.num%=p;
	else Max_gold.num=(abs(Max_gold.num)%p)*(-1);
	printf("%d",Max_gold.num);
	return 0;
}
