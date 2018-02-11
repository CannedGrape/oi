#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int s[1001]={0};
int main()
{
   int i,j,n,m,a,b,t;
   freopen("level.in","r",stdin);
   freopen("level.out","w",stdout);
   scanf("%d%d",&n,&m);
   for (i=0;i<m;i++)
   {
	scanf("%d",&a);
	for (j=0;j<a;j++)
	{
	 scanf("%d",&b);
	 s[b]++;
	}
   }
   t=s[1];
   for (i=1;i<=n;i++) if (s[i]>t) t=s[i];
   printf("%d\n",t);
  return 0;
}

