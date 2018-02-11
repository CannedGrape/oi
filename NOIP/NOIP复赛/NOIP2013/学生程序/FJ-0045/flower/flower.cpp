#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,a[100005];
struct gaod
{int shu,xing;};
struct gaod f[100005];
void pd(int x,int y)
{
    if(f[y].xing!=1&&a[x]>a[y])
       {if(f[x].shu<f[y].shu+1)
          {f[x].shu=f[y].shu+1;
           f[x].xing=1;
          }
       }
    else if(f[y].xing!=2&&a[x]<a[y])
       {if(f[x].shu<f[y].shu+1)
          {f[x].shu=f[y].shu+1;
           f[x].xing=2;
          }
       }
    else
       {if(f[x].shu<f[y].shu)
          {f[x].shu=f[y].shu;
           f[x].xing=f[y].xing;
          }
       }
}
void doit(int x)
{
     f[x].shu=0;
     for(int j=1;j<x;j++)
        {pd(x,j);}
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
       scanf("%d",&a[i]);
    if(n==1) {printf("1");return 0;}
    f[1].xing=0; f[1].shu=1;
    for(int i=2;i<=n;i++)
       doit(i);
    printf("%d",f[n].shu);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
