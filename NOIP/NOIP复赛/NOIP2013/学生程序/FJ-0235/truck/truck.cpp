#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int i,j,n,m,x,y,z,q,k;
int a[10001],b[10001],s[10001][10001];
int smin(int q,int p)
{   if(q>p)  return p;
    else   return q;
}
int main()
{   freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=m;i++)
       {cin>>x>>y>>z;
        s[x][y]=z;
	    s[y][x]=z;
	   }
	cin>>q;
	for(i=1;i<=q;i++)
	   cin>>a[i]>>b[i];
	for(k=1;k<=n;k++)
	   for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
		     { if(smin(s[i][k],s[k][j])>s[i][j] && s[i][k]!=0 && s[k][j]!=0)
		         s[i][j]=smin(s[i][k],s[k][j]);
			 }	   
	for(i=1;i<=q;i++)
	   { if(s[a[i]][b[i]]==0)  cout<<"-1"<<endl;
	     else  cout<<s[a[i]][b[i]]<<endl;
	   }

    return 0;
}
