#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{freopen("game.in","r",stdin);
 freopen("game.out","w",stdout);
 int n,i,j,a,b,maxn,minn;
 int l[1001],r[1001];
 int g[1001];
 cin>>n>>a>>b;
 for(i=1;i<=n;i++)
   g[i]=1;
 for(i=1;i<=n;i++)
   {cin>>l[i];
    cin>>r[i];
   }
 for(i=1;i<=n;i++)
   {for(j=1;j<=i-1;j++)
      g[i]=g[i]*l[j];
    g[i]=(a*g[i])/r[i];
   }
 maxn=0;
 for(i=1;i<=n;i++)
   {
    if(g[i]>maxn)
      maxn=g[i];
   }
 cout<<maxn;
 fclose(stdin);
 fclose(stdout);
 return 0;
}
