#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int n,k,m,s,t,u,v,dis;
long long sum=0,maxx=0;
int c[101];
bool a[101][101];
int d[101][101];
bool q[101];
void tryy(int now)
{
     if (now==t)
     {
        if (sum>maxx)
          maxx=sum;
     }
     else
     {
        int i;
        for (i=1;i<=n;i++)
          if (a[c[i]][c[now]]==0&&d[i][now]>0&&q[c[i]]==0)
          {
             sum=sum+d[i][now];
             q[c[i]]=1;
             tryy(i);
             q[c[i]]=0;
             sum=sum-d[i][now];
          }
     }
}
int main ()
{
    freopen("culture.in","r",stdin);
    freopen("culture.out","w",stdout);
    cin>>n>>k>>m>>s>>t;
    int i,j;
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        d[i][j]=0;
    for (i=1;i<=k;i++)
      q[i]=0;
    for (i=1;i<=n;i++)
      cin>>c[i];
    for (i=1;i<=k;i++)
      for (j=1;j<=k;j++)
        cin>>a[i][j];
    for (i=1;i<=m;i++)
    {
       cin>>u>>v>>dis;
       d[u][v]=dis;
       d[v][u]=dis;
    }
    q[c[s]]=1;
    tryy(s);
    if (maxx==0)
      cout<<-1;
    else
      cout<<maxx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
