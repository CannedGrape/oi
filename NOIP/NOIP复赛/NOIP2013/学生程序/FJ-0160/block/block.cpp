#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c,d,e,x,s,n;
    int m[100000];
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    cin>>n;
    int h[n];
    s=0;
    for(a=1;a<=n;a++)
      {cin>>h[a];
       s=s+h[a];}
    x=0;
    for(c=1;c<=n;c++)
      {if(h[c]>x)
         x=h[c];}
    int z[n][x];
    for(a=1;a<=n;a++)
      {for(b=1;b<=x;b++)
         {z[a][b]=0;}}
    for(a=1;a<=n;a++)
      {for(b=1;b<=h[a];b++)
         {z[a][b]=1;}}
    for(b=1;b<=x;b++)
      {for(a=1;a<=n;a++)
         {m[a]=z[a][b];
          if(a!=1&&m[a]==0&&m[a-1]!=0)
            {for(c=1;c<=a;c++)
               {m[c]=0;}
             s=s-a+1;}}}
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
