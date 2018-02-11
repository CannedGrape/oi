#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,s=0,x[10001][100],y[10001]={};
bool p[10001][100];
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    int i,j,k,l;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      for(j=0;j<m;j++)
        {
         cin>>p[i][j];
         if(p[i][j]==1)
           y[i]++;
         scanf("%d",&x[i][j]);
        }
    scanf("%d",&j);
    for(i=1;i<=n;i++)
      {
       s+=x[i][j];
       s%=20123;
       x[i][j]=(x[i][j]-1)%y[i]+1;
       for(k=j,l=0;l<x[i][j];k=(k+1)%m)
         if(p[i][k]==1)
           l++;
       k=(k+m-1)%m;
       j=k;
      }
    printf("%d\n",s);
    fclose(stdin);
    fclose(stdout);
    system("pause");
    return 0;
}
