#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
int i,j,k,n,m,ff[1005][1005],f[1005][1005],l,a[1000005],mi,ma,s[1005];
bool p[10005];
void tryy(int x)
{int i;
 for(i=1;i<=n;i++)
    if(ff[x][i]==1&&s[i]<=s[x])
      {s[i]=s[x]+1;
      tryy(i);}
}
int main()
{freopen("level.in","r",stdin);
 freopen("level.out","w",stdout);
 scanf("%d%d",&n,&m);
 for(i=1;i<=m;i++)
    {scanf("%d",&k);mi=100000000;ma=0;
     for(j=0;j<=n;j++)
        {a[j]=0;p[j]=0;}
     for(j=1;j<=k;j++)
        {scanf("%d",&l);p[l]=1;a[++a[0]]=l;ma=max(ma,l);mi=min(mi,l);}
     for(j=mi;j<=ma;j++)
        if(p[j]==0)
          for(k=1;k<=a[0];k++)
             {f[j][a[k]]=1;ff[a[k]][j]=1;}
    }ma=0;
 for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        {if(f[i][j]==1)
          f[i][0]++;}
 for(i=1;i<=n;i++)s[i]=0;
 for(i=1;i<=n;i++)
    if(f[i][0]==0)
      tryy(i);
 ma=0;
 for(i=1;i<=n;i++)
    ma=max(ma,s[i]);
 printf("%d\n",ma+1);
 fclose(stdin);
 fclose(stdout);
 //system("pause");
 return 0;
}
