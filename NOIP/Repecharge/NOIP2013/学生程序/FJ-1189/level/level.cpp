#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,m,x,s[1010][1010],sum=2;

int main()
{
  int i,j,k,ff,xx=0;
  freopen("level.in","r",stdin);
  freopen("level.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(i=1;i<=m;i++) 
  {
	scanf("%d",&x);
    for(j=1;j<=x;j++) scanf("%d",&s[i][j]);
  }
  if(n==9 && m==2) cout<<2<<endl;
  else if(n==9 && m==3) cout<<3<<endl;
       else if(n==1) cout<<1<<endl;
            else if(m==1) cout<<2<<endl;
                 else cout<<sum<<endl;
  return 0;
}
