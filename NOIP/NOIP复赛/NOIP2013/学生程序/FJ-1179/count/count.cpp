#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int n,x,ans,l=1;
int a[7];
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
	scanf("%d%d",&n,&x);
    a[6]=1;
    int i=1;
    while(i<=n)
    {
	  for(int j=6;j>6-l;j--)
	    if(a[j]==x)ans++;
	  a[6]++;
	  for(int j=6;j>6-l+1;j--)if(a[j]>9)a[j-1]++,a[j]=0;
	  for(int j=6-l+1;j>0;j--)
	    if(a[j]>9)a[j-1]++,a[j]=0,l++;
	    else break;
	  i++;
	}
	printf("%d",ans);
	return 0;
}