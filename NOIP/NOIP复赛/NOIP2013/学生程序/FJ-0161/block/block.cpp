#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
int c=0;
int flag=0;
int position[100000]={};
int h[100000]={},g[100000]={},l[100000],ans=0;  //h：目标高度 g：当前高度 
void solve(int d)
{ 
    if(c==n-1)return;
    int k,jiluz=0,jiluy=0;
    while(g[d]<h[d])
    {
    for(k=d;k>=0;k--)
      {
      if(g[k]>=h[k]){break;}
      }
    jiluz=k+1;
    for(k=d;k<=n-1;k++)
      {
      if(g[k]>=h[k]){break;}
      }
    jiluy=k-1;
    for(k=jiluz;k<=jiluy;k++)
      {
      g[k]=g[k]+1;
      }
    ans++;
    }
    c++;
    solve(l[c]);
    return;
}
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int i,j;
    scanf("%d", &n);
    for(i=0;i<n;i++)
      {
      scanf("%d", &h[i]);
      l[i]=h[i];
      }
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        {
        if(h[j]>h[i]&&j!=i)position[i]++;
        if(h[i]==h[j]&&i>j)position[i]++;
        }
    for(i=0;i<=n-1;i++)
      {
      for(j=0;j<=n-1;j++)
      if(position[j]==i)l[i]=j;
      }
    solve(l[c]);
    cout<<ans;
    cout<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
