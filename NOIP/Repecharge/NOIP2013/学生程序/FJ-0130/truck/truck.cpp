#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<fstream>
int n,m,q,dis=-1,a,b;
int x[50001],y[50001],z[50001];
int o;
void sovel(int v,int g,int *l)
{
     
    if(x[v]==y[g])
      {if(z[v]>z[g])
      *l=z[g];
      else
      *l=z[v];
      g++;}
    if(v!=m&&g!=m)
    sovel(v+1,g,l);
    else
    if(v==m&&g!=m)
    sovel(v,g+1,l);
}
using namespace std;
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&n,&m);
    int adis[n+1],bdis[n+1];
    for(int i=1;i<=m;i++)
    scanf("%d%d%d",&x[i],&y[i],&z[i]);
    scanf("%d",&q);
    for(int i=1;i<=q;i++)    //main
      {dis=-1;
      scanf("%d%d",&a,&b);
      memset(adis,0,sizeof(adis));
      memset(bdis,0,sizeof(bdis));
      for(int s=1;s<=m;s++)
      {if(x[s]==a)
      adis[y[s]]=z[s];
      else
      if(x[s]==b)
      bdis[y[s]]=z[s];
      else
      if(y[s]==a)
      adis[x[s]]=z[s];
      else
      if(y[s]==b)
      bdis[x[s]]=z[s];}
      for(int s=1;s<=m;s++)
      if(adis[s]!=0&&bdis[s]!=0)
        if(dis<adis[s]&&dis<bdis[s])
        {if(adis[s]>bdis[s])
        dis=bdis[s];
        else
        dis=adis[s];}
      if(dis<adis[b]&&adis[b]!=0)
      dis=adis[b];
      for(int s=1;s<=m;s++)
        for(int j=s+1;j<=m;j++)
        if(x[s]==y[j])
        {
         if(z[s]>z[j])
         o=z[j];
         else
         o=z[s];
         sovel(s=1,j+1,&o);}
        else
        if(x[j]==y[s])
        {
         if(z[j]>z[s])
         o=z[s];
         else
         o=z[j];
         sovel(j+1,s+1,&o);}
      if(o>dis)
      dis=o;
      printf("%d\n",dis);}
    return 0;
}
