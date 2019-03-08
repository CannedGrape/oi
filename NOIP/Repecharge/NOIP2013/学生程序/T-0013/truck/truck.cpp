#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int second;
int les=210000000,least=210000000;
int maps[1001][1001];
int bol[1001][1001];
int themaxlist[1001][1001];
int n,m,k;
int x[10001],y[10001],z[10001],q1[10001],q2[10001];
void maxlist(int first)
{
     for(int i=1;i<=n;i++)
       if(maps[first][i]!=-1&&bol[first][i]==0)
       {
            least=les;                 
            if(maps[first][i]<les)
              les=maps[first][i];
            bol[first][i]=1;
            bol[i][first]=1;  
            if(les>themaxlist[second][i])
              themaxlist[second][i]=les;
            maxlist(i);
            les=least;
            bol[first][i]=0;
            bol[i][first]=0;
       }
}      
void init()
{
     for(int i=1;i<=1000;i++)
       for(int j=1;j<=1000;j++)
       {themaxlist[i][j]=-1;maps[i][j]=-1;}
     scanf("%d%d",&n,&m);
     for(int i=1;i<=m;i++)
     {scanf("%d%d%d",&x[i],&y[i],&z[i]);maps[x[i]][y[i]]=z[i];maps[y[i]][x[i]]=z[i];}
     for(int i=1;i<=n;i++)
     {second=i;maxlist(i);}
     scanf("%d",&k);  
     for(int i=1;i<=k;i++)
     {scanf("%d%d",&q1[i],&q2[i]);printf("%d\n",themaxlist[q1[i]][q2[i]]);}  
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    init();
    return 0;
}
