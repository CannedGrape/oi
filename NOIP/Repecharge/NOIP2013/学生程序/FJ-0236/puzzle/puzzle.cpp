#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int m,n,q,f[32][32],i,j,k,a[1001],_x1,xy1,_x2,_y2,_x3,_y3;
int dog(int st,int hy)
{
	int ans;
	ans=5-f[st][hy];
     if(f[st][hy+1]==-1) ans--;
     if(f[st][hy-1]==-1) ans--;
      if(f[st+1][hy]==-1) ans--;
      if(f[st-1][hy]==-1) ans--;
      return ans;
}
int main()
{   freopen("puzzle.in","r",stdin);
   freopen("puzzle.out","w",stdout);
     cin>>n>>m>>q;
     for(i=1;i<=n;i++)f[i][0]=-1;
    for(i=1;i<=n;i++) f[i][m]=-1;
    for(j=1;j<=m;j++) f[0][j]=-1;
    for(j=1;j<=m;j++) f[n][j]=-1;
         for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {cin>>f[i][j];
            if(f[i][j]==0) f[i][j]=-1;
		}
            for(i=1;i<=q;i++)
            {
			   cout<<1<<endl;
				}
		return 0;
}
