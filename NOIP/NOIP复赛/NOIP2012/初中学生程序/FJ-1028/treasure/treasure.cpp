#include<iostream>
#include<cstdio>
using namespace std;
const int mod=20123;
int n=0,m=0,a[10001][101]={},l=0,p=0,sum=0,num[10001]={};
bool b[10001][101]={};
int main()
{   freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    scanf("%d%d",&n,&m);
    int i=0,j=0;
    l=m*n;
    for(i=1;i<=n;i++)
      for(j=0;j<m;j++)
        {scanf("%d%d",&b[i][j],&a[i][j]);
         if(b[i][j])
           num[i]++;
        }
    scanf("%d",&p);
    for(i=1;i<=n;i++)
      {sum+=a[i][p];
       sum%=mod;
       int x=a[i][p]%num[i],t=0;
       if(x==0)
         {p--;
          while(b[i][p]==false)
            {p--;
             if(p<0)
               p+=m;
            }
          continue;
         }
       if(b[i][p])
         t++;
       while(t<x)
         {p++;
          p%=m;
          if(b[i][p])
            t++;
         }
      }
    printf("%d\n",sum);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
