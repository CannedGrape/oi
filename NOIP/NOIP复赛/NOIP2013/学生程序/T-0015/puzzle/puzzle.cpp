#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,mm,ans,x0[1000001],yy0[1000001],x1[1000001],yy1[1000001],x2[1000001],yy2[1000001],q[1000001],x3,yy3;
int kx[5]={0,1,0,-1,0},ky[5]={0,0,1,0,-1};
bool p[31][31];
int solve(int e1,int e2,int s1,int s2)
{
    int i,h,t,w1,w2;
	x0[1]=0;yy0[1]=0;x1[1]=e1;yy1[1]=e2;x2[1]=s1;yy2[1]=s2;q[1]=0;
    h=0;t=1;
    while (h<t)
    {
      h++;
      for (i=1;i<=4;i++)
      {
        w1=x1[h]+kx[i];
        w2=yy1[h]+ky[i];
        if (w1>0&&w1<=n&&w2>0&&w2<=m&&(w1!=x0[h]||w2!=yy0[h])&&p[w1][w2]==1)
        {
          t++;
          if (t>900000) {ans=-1;printf("%d\n",ans);return 0;}
          q[t]=q[h]+1;
          x0[t]=x1[h];yy0[t]=yy1[h];
          x1[t]=w1;yy1[t]=w2;
          x2[t]=x2[h];yy2[t]=yy2[h];
          if (w1==x2[h]&&w2==yy2[h])
          {
            x2[t]=x1[h];yy2[t]=yy1[h];
          }
          if (x2[t]==x3&&yy2[t]==yy3) {ans=q[t];printf("%d\n",ans);return 0;}
        }
      }
    }
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int i,j,x,s1,s2,e1,e2;
    scanf("%d%d%d",&n,&m,&mm);
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
        scanf("%d",&x);
        p[i][j]=x;
      }
    for (i=1;i<=mm;i++)
    {
      scanf("%d%d%d%d%d%d",&e1,&e2,&s1,&s2,&x3,&yy3);
      solve(e1,e2,s1,s2);
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
