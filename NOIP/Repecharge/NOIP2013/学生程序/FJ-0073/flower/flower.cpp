#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int n,ans;
int h[100001];
int rl[100001],rh[100001];
int main()
{
 freopen("flower.in","r",stdin);
 freopen("flower.out","w",stdout);
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
	scanf("%d",&h[i]);
 for(int i=1;i<=n;i++)
    {for(int j=1;j<=i-1;j++)
	   {
		 if(h[j]<h[i]&&rl[j]>rh[i]) rh[i]=rl[j];
	     if(h[j]>h[i]&&rh[j]>rl[i]) rl[i]=rh[j];
	   }
	  rl[i]+=1;rh[i]+=1;
	}
  for(int i=1;i<=n;i++)
    {if(ans<rl[i])ans=rl[i];
	  if(ans<rh[i])ans=rh[i];
	}
   printf("%d\n",ans);
return 0;	
}