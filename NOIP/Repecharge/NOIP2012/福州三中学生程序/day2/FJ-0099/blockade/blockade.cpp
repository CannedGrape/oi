#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int n,u,v,w,m,lu[10001][10001]={},s=0,mz[50001]={},mj,maxx=0;
int main()
{   freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
    int i;scanf("%d",&n);
    for(i=1;i<=n-1;i++){scanf("%d %d %d",&u,&v,&w);
         lu[u][v]=w;lu[v][u]=w;
         if(w>maxx)maxx=w;
        }scanf("%d",&m);
    for(i=1;i<=m;i++){scanf("%d",&mj);mz[mj]++;}
    for(i=2;i<=n;i++)
      if(lu[1][i]!=0)s++;
    if(s>m){printf("-1\n");fclose(stdin);fclose(stdout);return 0;}
    printf("%d",maxx);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
