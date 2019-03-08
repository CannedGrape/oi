#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int f[10010][3];
int g[10010][3];
int n,a[10010];

int mymax (int a,int b)
{
    if (a>b)  return a;
    return b;
}

void init ()
{
     int i;
     cin>>n;
     for (i=1;i<=n;i++)
       scanf ("%d",&a[i]);
}

void doing ()
{
     int i,j;
     int ans=0;
     /*g[0][1]=2147483647;
     g[0][2]=-1;*/
     g[1][1]=a[1];f[1][1]=1;
     g[1][2]=a[1];f[1][2]=1;
     for (i=2;i<=n;i++)
       for (j=1;j<i;j++)
       {
           if (a[i]<g[j][1])
           {
             f[i][2]=mymax(f[i][2],f[j][1]+1);
             g[i][2]=a[i];
             ans=mymax(ans,f[i][2]);
           }
           if (a[i]>g[j][2])
           {
             f[i][1]=mymax(f[i][1],f[j][2]+1);
             g[i][1]=a[i];
             ans=mymax(ans,f[i][1]);
           }
       }
     cout<<ans<<endl;
}

int main ()
{
    freopen ("flower.in","r",stdin);
    freopen ("flower.out","w",stdout);
    
    init ();
    doing ();
    
    //system ("pause");
    return 0;
}
