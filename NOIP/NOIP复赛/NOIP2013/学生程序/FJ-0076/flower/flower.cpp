#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
int x,n,h[100001]={},g[100001][3]={},j;
bool f=true,ff=true,p[100001][3]={};
int main()
{
    ;
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      {scanf("%d",&h[i]);
      p[i][1]=true;
      p[i][2]=false;
      g[i][1]=g[i][2]=1;
      if(h[i]!=h[1]&&f==true)
        {f=false;
        x=i;
        }
      }
      p[1][1]=true;
    p[1][2]=false;
    for(int i=x;i<=n;i++)
    {j=i-1;
    f=false;ff=false;
    while((f==false||ff==false)&&j>0)
    {
       if(p[j][1]==true&&h[i]<h[j])
         {g[i][2]=max(g[j][1]+1,g[i][2]);
         p[i][2]=false;
         f=true;
         }
       if(p[j][2]==false&&h[i]>h[j])
       {g[i][1]=max(g[j][2]+1,g[i][1]);
       p[i][1]=true;
       ff=true;
       }
       j--;
    }
    }
    int maxx=0;
    for(int i=1;i<=n;i++)
      for(j=1;j<=2;j++)
        if(g[i][j]>maxx)
          maxx=g[i][j];
    printf("%d\n",maxx);
    //system("pause");
    return 0;
}
    
