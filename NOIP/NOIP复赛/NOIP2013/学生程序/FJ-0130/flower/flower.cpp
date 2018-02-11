#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int h[100000],k[100000],g[100000],n,t=0,i,r,e=0,c=0,z=0;
void flower (int l,int u,int *s) //l为此次去掉的花 u表示剩余的花 
{   
    if(u==1&&l>n)
    return;
    if(l>n&&h[l-2]!=0)
    {for(int i=1;i<=n;i++)
    if(h[i]==0)
      h[i]=k[i];
    for(int i=1;i<=n-u;i=i+c)
      h[i+z]=0;
    z++;
    flower(1,u,s);}
    else
    if(h[l]==0)
    flower(l++,u,s);
    if(l>n&&h[l-2]==0)
    c++;
    flower(1,u,s);
    if(c>(u/(n-u)-2))
    flower(1,u--,s);
    h[l]==0;
    for(int i=1;i<=n;i++)
    if(h[i]!=0)
    {t++;
    g[t]=h[i];}
    if(u%2==0)
    r=u-1;
    else;
    r=u;
    for(int i=1;i<=r/2;i++)
    if(g[r*2-1]<g[r*2]&&g[r*2+1]<g[2*r])
    e=1;
    else
    {e=0;
    break;}
    for(int i=1;i<=r/2;i++)
    if(g[r*2-1]>g[r*2]&&g[r*2+1]>g[2*r])
    e=1;
    else
    {e=0;
    break;}
    if(e==1&&(*s<u))
    *s=u;
    flower(l++,u,s);
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);    
    cin>>n;
    if(n==1)
    {printf("1");
    return 0;}
    int b=n;
    int s=n;
    for(int i=1;i<=n;i++)
    {scanf("%d",&h[i]);
     k[i]=h[i];}
     flower(0,n,&b);
     cout<<b;
    return 0;
}
