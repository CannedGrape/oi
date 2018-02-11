#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <cstring>
using namespace std;
long long x,y,xx,yy,k;
void work(int a,int b)
{
     if (a%b!=0) work(b,a%b);
     if (a%b) {x=y; y=xx-(a/b*x);}
     xx=x; yy=y;
}
int main()
{
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    int a,b;
    scanf("%d%d",&a,&b);
    xx=x=0; yy=y=1;
    if (a>b)
      {work(a,b);
       while (xx<=0) xx+=b;  
       while (xx>b) xx-=b;
       cout<<xx<<endl;
      }
    else
      {work(b,a);
       while (yy<0) yy+=b;
       while (yy>b) yy-=b;
       cout<<yy<<endl; 
      }  
    fclose(stdin);
    fclose(stdout);
    return 0;
}
