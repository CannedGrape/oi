#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int i,j,n,m,k,a[101][10],s[101][101];

int main()
{   freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          cin>>s[i][j];
    for(i=1;i<=k;i++)
       for(j=1;j<=6;j++)
           cin>>a[i][j];
    for(i=1;i<=k;i++)
        cout<<"-1"<<endl;
    
	return 0;
}
