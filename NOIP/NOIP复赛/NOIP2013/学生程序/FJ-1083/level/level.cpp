#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,m,s,_,ans=1,___=-INF,l_;
bool x[1001],flag,__=true;
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
      {
      scanf("%d",&s);
      flag=false;
      l_=0;
      for(int j=1;j<=s;j++)
        {
        scanf("%d",&_);
        l_=_;
        if(___==-INF)
          ___=_;
        if(_<___)
          flag=true;
        if(_-l_>1)
          __=false;
        if(!x[_] && !flag)
          ans++,flag=true;
        x[_]=true;
        }
      }
    printf("%d\n",(__?1:ans));
    return 0;
}
