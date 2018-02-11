#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,k,t,w,f[101]={},x[101],y[101][101],s=0,e=100000000;
bool p[101][101];
inline void ss(int a)
{
       if(a==w)
         {
          e=min(s,e);
          return;
         }
       int i,j;
       for(i=1;i<=n;i++)
         if(((f[x[i]]==0)||(i==w))&&(y[i][a]<100000000))
           {
            f[x[i]]++;
            for(j=1;j<=k;j++)
              if(p[j][x[i]]==1)
                f[j]++;
            s+=y[i][a];
            ss(i);
            s-=y[i][a];
            f[x[i]]--;
            for(j=1;j<=k;j++)
              if(p[j][x[i]]==1)
                f[j]--;
           }
}
int main()
{
    freopen("culture.in","r",stdin);
    freopen("culture.out","w",stdout);
    int i,j,l;
    scanf("%d%d%d%d%d",&n,&k,&m,&t,&w);
    for(i=1;i<=n;i++)
     scanf("%d",&x[i]);
    for(i=1;i<=k;i++)
      for(j=1;j<=k;j++)
        cin>>p[i][j];
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        y[i][j]=100000000;
    while(m>0)
      {
       m--;
       scanf("%d%d%d",&i,&j,&l);
       y[i][j]=y[j][i]=min(y[i][j],l);
      }
    if((p[x[w]][x[t]]==1)||(x[t]==x[w]))
      printf("-1\n");
    else
      {
       f[x[t]]++;
       f[x[w]]++;
       for(i=1;i<=k;i++)
         {
          if(p[i][x[t]]==1)
            f[i]++;
          if(p[x[w]][i])
            f[i]++;
         }
       ss(t);
       printf("%d\n",e);
      }
    fclose(stdin);
    fclose(stdout);
    system("pause");
    return 0;
}
