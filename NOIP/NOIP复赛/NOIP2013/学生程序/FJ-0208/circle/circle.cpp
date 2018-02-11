#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN=1000005,MAXL=100;
typedef long long LL;
int n,m,x,k;
bool flag[MAXN],xb[MAXN];
int tot,s[MAXN]; 
LL t,ans;
int main()
{ 
  freopen("circle.in","r",stdin);
  freopen("circle.out","w",stdout);
  scanf("%d%d%d%d",&n,&m,&k,&x);
  memset(flag,0,sizeof(flag));
  tot=0;
  s[tot]=x; flag[x]=true; xb[x]=0;
  while (1) 
    { 
	  x+=m; x%=n; tot++; 
	  if (flag[x]) break;
	  flag[x]=true; s[tot]=x; xb[x]=tot; 
	} 
//cout<<tot<<endl;
  LL tt=LL(tot);
  ans=1; t=10; 
  while (k)
    { 
	  int temp=k%2;
	  if (temp) ans*=t,ans%=tt;
	  k/=2; t=t*t%tt; 
    } 
  //cout<<ans<<endl;
  ans%=tt; 
  int ti=int(ans);
  printf("%d\n",s[ti]);
  //cout<<tot<<endl;
  //for (int i=0;i<=tot-1;i++) 

  return 0;
}
