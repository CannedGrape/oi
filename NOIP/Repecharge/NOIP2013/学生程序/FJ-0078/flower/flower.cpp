#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<fstream>
using namespace std;
#define maxint (1<<29)
#define minint (-maxint)
#define MAXN 1000001
int n,h[MAXN],f[MAXN],g[MAXN],ans=minint;
inline int max(int a,int b,int c)
{
       return max(max(a,b),c);
}
inline void init()
{
       scanf("%d",&n);
       register int i;
       for(i=1;i<=n;i++)
         scanf("%d",&h[i]);
}
inline void solve()
{
       register int i,j;
       f[1]=g[1]=1;
       for(i=1;i<=n;i++)
         f[i]=g[i]=1;
       for(i=2;i<=n;i++)
         for(j=1;j<i;j++){
             if((h[i]>h[j]&&(f[j]&1))||(h[i]<h[j]&&(f[j]%2==0)))
               f[i]=max(f[i],f[j]+1);
             if((h[i]>h[j]&&(g[j]%2==0))||(h[i]<h[j]&&(g[j]&1)))
               g[i]=max(g[i],g[j]+1);
         }
       for(i=1;i<=n;i++)
         ans=max(ans,f[i],g[i]);
       /*for(i=1;i<=n;i++)
         cout<<f[i]<<" ";cout<<endl;
       for(i=1;i<=n;i++)
         cout<<g[i]<<" ";cout<<endl;*/
       printf("%d\n",ans);
}
inline void rat()
{
       register int i,j;
       f[1]=g[1]=1;
       for(i=1;i<=n;i++)
         f[i]=g[i]=1;
       for(i=2;i<=n;i++)
         if(i<=300)
           for(j=1;j<i;j++){
              if((h[i]>h[j]&&(f[j]&1))||(h[i]<h[j]&&(f[j]%2==0)))
                f[i]=max(f[i],f[j]+1);
              if((h[i]>h[j]&&(g[j]%2==0))||(h[i]<h[j]&&(g[j]&1)))
                g[i]=max(g[i],g[j]+1);
           }
         else
           for(j=i-250;j<i;j++){
              if((h[i]>h[j]&&(f[j]&1))||(h[i]<h[j]&&(f[j]%2==0)))
                f[i]=max(f[i],f[j]+1);
              if((h[i]>h[j]&&(g[j]%2==0))||(h[i]<h[j]&&(g[j]&1)))
                g[i]=max(g[i],g[j]+1);
           }
       for(i=1;i<=n;i++)
         ans=max(ans,f[i],g[i]);
       printf("%d\n",ans);
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    init();
    if(n<=10000)
      solve();
    else
      rat();
    fclose(stdout);
    fclose(stdin);
    //system("pause");
    return 0;
}
/*
5
5 3 2 1 2

15
1 1 3 2 2 4 5 6 0 10 1 8 9 6 7

8
6 5 3 5 10 9 10 9

*/
