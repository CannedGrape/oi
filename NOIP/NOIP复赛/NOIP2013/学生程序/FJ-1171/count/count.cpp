#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int n,x,ans=0,p;
int main()
{
 freopen("count.in","r",stdin);
 freopen("count.out","w",stdout); 
 scanf("%d%d",&n,&x);
 for (int i=1;i<=n;i++)
  {
   p=i;
   while(p!=0) {if (p%10==x) ans++;p/=10;}
  }
 printf("%d\n",ans);
}
