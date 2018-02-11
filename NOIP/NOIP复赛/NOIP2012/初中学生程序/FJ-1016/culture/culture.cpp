#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;
int ans=2147483647,temp=0;
short n,k,m,s,t,c[101],d[10000][3],now;
bool p[100][100],ok=false;
void go(int r)
{ temp+=d[r][2];
  if(d[r][1]==t)
  { if(ans>temp)
     ans=temp;
    ok=true;
    return;
  }
  now=d[r][1];
  short i;
  for(i=0;i<m;i++)
   if(c[now]!=c[d[i][1]-1]||!p[c[d[i][1]-1]-1][c[now]-1])
    go(i);
  temp-=d[r][2];
}
int main()
{ freopen("culture.in","r",stdin);
  freopen("culture.out","w",stdout);
  short i,j;
  cin>>n>>k>>m>>s>>t;
  for(i=1;i<=n;i++)
   cin>>c[i];
  for(i=0;i<k;i++)
   for(j=0;j<k;j++)
    cin>>p[i][j];
  for(i=0;i<m;i++)
   for(j=0;j<3;j++)
    cin>>d[i][j];
  now=s;
  if(!p[c[t]-1][c[s]-1])
   for(i=0;i<m;i++)
    if(c[now]!=c[d[i][1]-1]||!p[c[d[i][1]-1]-1][c[now]-1])
     go(i);
  if(ok)
   cout<<ans<<endl;
  else
   cout<<"-1"<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
