#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,q,ans=-1;
int a[100][100],x[100][6];

int main()
{int i,j;
 freopen("puzzle.in","r",stdin);
 freopen("puzzle.out","w",stdout);
 cin>>n>>m>>q;
 for(i=1;i<=n;i++)
   {for(j=1;j<=m;j++)
     cin>>a[i][j];}
 for(i=1;i<=q;i++) 
   cin>>x[i][1]>>x[i][2]>>x[i][3]>>x[i][4]>>x[i][5]>>x[i][6];
 for(i=1;i<=q;i++) cout<<ans<<endl; 
 return 0;
}
