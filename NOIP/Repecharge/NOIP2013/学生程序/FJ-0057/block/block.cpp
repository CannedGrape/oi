#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int h[100005]={},f[100005]={};
void input()
{
     scanf("%d",&n);
     for(int i=1;i<=n;++i)
       scanf("%d",&h[i]);
}
void work()
{
     f[1]=h[1];
     for(int i=2;i<=n;++i)
       if( h[i]>h[i-1] ) f[i]=f[i-1]+h[i]-h[i-1];
       else f[i]=f[i-1];
     printf("%d\n",f[n]);
}
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    input();
    work();
    fclose(stdin);
    fclose(stdout);
return 0;
}
