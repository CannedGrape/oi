#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
   int i,k,n,x;
   long long s=0;
   freopen("count.in","r",stdin);
   freopen("count.out","w",stdout);
   scanf("%d%d",&n,&x);
   for (i=1;i<=n;i++)
   {
    k=i;
	while (k>0)
	{
	 if (k%10==x) s++;
	 k/=10;
	}
   }
   cout<<s<<endl;
  return 0;
}

