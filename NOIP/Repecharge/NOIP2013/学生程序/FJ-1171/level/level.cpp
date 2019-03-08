#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1001],n,m,ans,end=1;
int main()
{
 freopen("level.in","r",stdin);
 freopen("level.out","w",stdout); 
 int l,p,pd;
 scanf("%d%d",&n,&m);
 for (int i=1;i<=n;i++) a[i]=0;
 scanf("%d",&l);
 for (int x=0;x<l;x++)
 {
  scanf("%d",&p);
  a[p]=1;
  if (p>end) end=p;
 }
 ans=1;
 for (int i=1;i<m;i++)
 {pd=0;
  scanf("%d",&l);
   for (int x=0;x<l;x++)
   {
    scanf("%d",&p);
    if (p>end) end=p;
    if (a[p]==0)
	 if (pd==0)
	 {ans++;pd=1;a[p]=1;}
     else a[p]=1;
   }
 }
 for (int i=1;i<=end;i++) if (a[i]==0) {ans++;break;}
 printf("%d\n",ans);
}
