#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

char jj;
int a[300001],tot;
int ans;

void jd();

int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    do{jd();}
    while(jj=='+');
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

void jd()
{
     int x,y;   
     scanf("%d",&x);
     x=x%10000;
     scanf("%c",&jj);
     if(jj!='*')
     {
                             ans=(ans+x)%10000;
                             return;                   
     }
     y=x;
     do
     {
                                  scanf("%d",&x);
                                  x=x%10000;
                                  y=y*x%10000;
                                  scanf("%c",&jj);
     }
     while(jj=='*');
     ans=(ans+y)%10000;
     return;
}
