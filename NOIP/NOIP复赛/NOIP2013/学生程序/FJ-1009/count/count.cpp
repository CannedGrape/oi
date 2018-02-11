#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int n,x;
int tot=0;
void init()
{
     scanf("%d%d",&n,&x);
     for(int i=1;i<=n;i++)
     {
          int k=i;   
          while(k>0)
          {if(k%10==x)tot++;k/=10;}
     }
     printf("%d\n",tot);
}
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    init();
    //system("pause");
    return 0;
}   
