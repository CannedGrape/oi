#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int a[1000001]={0},ts[1000001]={0},ans[1000001]={0},n=0,maxn=-10000001,h=0,p=0;
void find(int l)
{
	for(int j=1;j<=l;j++)
	{
	   h=0;
	   for(int k=0;k<=l-j;k++)
	   {
		  h+=a[j+k];
		  if(h>maxn)maxn=h;
	   }
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin >> n >> p;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		maxn=-10000001;
		find(i);
		ts[i]=maxn;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1)ans[i]=ts[i];
		else
		{
		  int mos=-100001;
		  for(int k=1;k<i;k++){if(ts[k]+ans[k]>mos)mos=ts[k]+ans[k];}
		  ans[i]=mos;
		  if(ans[i]>=0)ans[i]%=p;
		  if(ans[i]<0)ans[i]=abs(ans[i])%p*-1;
		}
	}
	maxn=-10000001;
	for(int i=1;i<=n;i++)if(ans[i]>maxn)maxn=ans[i];
	cout << maxn << endl;
	return 0;
}
