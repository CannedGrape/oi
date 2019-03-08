#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,k;
int h[100005]={},f[100005]={};
bool b[100005]={};
void input()
{
     scanf("%d",&n);
     scanf("%d",&h[1]);
     int a;
     k=1;
     for(int i=2;i<=n;++i)
       {
        scanf("%d",&a);
        if( a!=h[k] )
          {++k;
           h[k]=a;
           if(h[k]>h[k-1]) b[k]=1;
          }
       }
}
void work()
{
     if(k==1) 
       {printf("1\n");
        return ;
       }
     b[1]=!b[2];
     f[1]=1;
     for(int i=2;i<=k;++i)
       if( b[i]!=b[i-1] ) f[i]=f[i-1]+1;
       else f[i]=f[i-1];
     printf("%d\n",f[k]);
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    input();
    work();
    fclose(stdin);
    fclose(stdout);
return 0;
}
