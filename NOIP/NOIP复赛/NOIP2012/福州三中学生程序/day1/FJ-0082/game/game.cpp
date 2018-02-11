#include<iostream>
#include<cstdio>
using namespace std;
double f[1001],g[1001],ans;
int n,a[1001],b[1001],c[1001];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    
    int i,j,z;
    double q,t;
    scanf("%d%d%d",&n,&a[0],&b[0]);
    for(i=1;i<=n;i++)
      scanf("%d%d",&a[i],&b[i]);
    f[0]=1;
    for(i=1;i<=n;i++)
      {z=i,q=f[i-1]*a[c[i-1]];
       q/=b[i];
       for(j=i-1;j>=1;j--)
         {t=g[j]*a[i];
          if(t<q||(t==q&&a[i]<a[j]))
            {z=j;
             q=t;
             }
          }
       for(j=i-1;j>=z;j--)
         {f[j+1]=f[j]*a[i];
          c[j+1]=c[j];
          }
       c[z]=i;
       q=1.0;
       for(j=0;j<=z-1;j++)
         q=a[c[j]]*q;
       f[z]=q;
       g[i]=f[i]/b[c[i]];
       for(j=i-1;j>=1;j--)
         if(f[j]/b[c[j]]>g[j+1])
           g[j]=f[j]/b[c[j]];
         else
           g[j]=g[j+1];
       }
    for(j=1;j<=n;j++)
      if(f[j]/b[c[j]]>ans)
        ans=f[j]/b[c[j]];
    printf("%.0lf\n",ans);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
