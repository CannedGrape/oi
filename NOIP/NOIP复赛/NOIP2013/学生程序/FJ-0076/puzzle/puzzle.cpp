#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,q,a[31][31]={},dx[5]={0,1,0,-1,0},dy[5]={0,0,1,0,-1},ans1=1000,ans2=1000,f=false,g[31][31]={},h[31][31]={},x=0,ans=0,t=0,EX,EY,SX,SY,TX,TY;
void dfs1(int x,int y)
{
     for(int i=1;i<=4;i++)
       if(x+dx[i]<=n&&x+dx[i]>0&&y+dy[i]>0&&y+dy[i]<=n&&a[x+dx[i]][y+dy[i]]==1&&g[x+dx[i]][y+dy[i]]==0)
       {t++;
       g[x+dx[i]][y+dy[i]]=1;
       if(x+dx[i]==EX&&y+dy[i]==EY&&t<ans1)
          {ans1=t;}
       else
         dfs1(x+dx[i],y+dy[i]);
       t--;
       g[x+dx[i]][y+dy[i]]=0;
       }
}
void dfs2(int x,int y)
{
     if(x>20000000)
     return;
     for(int i=1;i<=4;i++)
       {if((x+dx[i]<=n)&&(x+dx[i]>0)&&(y+dy[i]>0)&&(y+dy[i]<=m)&&(a[x+dx[i]][y+dy[i]]==1)&&(h[x+dx[i]][y+dy[i]]==0||(x+dx[i]==SX&&y+dy[i]==SY)))
       {x++;
       if(f==true)
         t++;
       h[x+dx[i]][y+dy[i]]=1;
       if(x+dx[i]==TX&&y+dy[i]==TY)
       f=true;
       if(x+dx[i]==SX&&y+dy[i]==SY&&t<ans2)
          ans2=t;
       else
         dfs2(x+dx[i],y+dy[i]);
       t--;
       if(x+dx[i]==TX&&y+dy[i]==TY)
       f=false;
       h[x+dx[i]][y+dy[i]]=0;
       x--;
       }
       }
}
int main()
{
    //freopen("puzzle.in","r",stdin);
    //freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
    for(int i=1;i<=q;i++)
      {scanf("%d%d%d%d%d%d",&EX,&EY,&SX,&SY,&TX,&TY);
      dfs1(SX,SY);
      t=0;
      dfs2(SX,SY);
      if(x>20000000)
        printf("-1\n");
      else
        {for(int i=1;i<=ans1;i++)
           ans+=i;
        ans-=ans2;
        printf("%d\n",ans);
        }
        }
    system("pause");
    return 0;
}
      
