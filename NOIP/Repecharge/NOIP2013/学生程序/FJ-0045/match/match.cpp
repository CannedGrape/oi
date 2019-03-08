#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int n;
long long tot=0;
int a[100005],b[100005];
void change(int x,int y)
{
   int t;
   tot=tot+(y-x);
   t=b[y];
   for(int k=x+1;k<=y;k++)
      b[k]=b[k-1];
   b[x]=t; 
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
       scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
       scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
       {if(a[i]!=b[i])
           {for(int j=i+1;j<=n;j++)
               if(b[j]==a[i]&&b[j]!=a[j])
               change(i,j);
           }
       }
    printf("%lld\n",tot%99999997);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
