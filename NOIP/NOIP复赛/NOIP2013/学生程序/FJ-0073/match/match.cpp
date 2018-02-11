#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
struct ty{int a,b;};
int n;
ty a1[100001],a2[100001];
int x1[100001];
bool cmp(ty q,ty w)
{if(q.a<w.a) return true;
 return false;
}
int main()
{
 freopen("match.in","r",stdin);
 freopen("match.out","w",stdout);
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
    {scanf("%d",&a1[i].a);a1[i].b=i;}
  for(int i=1;i<=n;i++)
    {scanf("%d",&a2[i].a);a2[i].b=i;}
 sort(a1+1,a1+n+1,cmp);
 sort(a2+1,a2+n+1,cmp);
 for(int i=1;i<=n;i++)
   {x1[a1[i].b]=(a2[i].b-a1[i].b);
	 if(a1[i].b>a2[i].b)
	   {for(int j=a2[i].b;j<=a1[i].b;j++)
			if(x1[j]>0)x1[j]--;
	   }
	 if(a1[i].b<a2[i].b)
	   {for(int j=a1[i].b;j<=a2[i].b;j++)
		    if(x1[j]<0)x1[j]++;
	   }
	
   }
 int ans=0;
 for(int i=1;i<=n;i++)
	ans+=(abs(x1[i])%99999997);
 printf("%d\n",ans);
 return 0;
}
