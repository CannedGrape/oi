#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
int n,h[100001]={};
int ans=0,y;
void work(int l,int r)
{
     if(l>r)
       return;
     if(l==r)
       {ans+=h[l];h[l]=0;
       return;
       }
     int minn=100000,x,j;
     for(j=l;j<=r;j++)
       if(h[j]<minn)
       {minn=h[j];
       x=j;
       }
       ans+=minn;
       for(j=l;j<=r;j++)
         h[j]-=minn;
       if(l<=x)
       work(l,x-1);
       if(y<=r)
       work(x+1,r);
}
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&h[i]);
    work(1,n);
    printf("%d\n",ans);
    //system("pause");
    return 0;
}
