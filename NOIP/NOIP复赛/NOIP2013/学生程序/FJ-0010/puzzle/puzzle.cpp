#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int i,j,n,m,q,ch,ans;
int ex[501],ey[501],sx[501],sy[501],tx[501],ty[501];
bool d[32][32];
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for(i=0;i<=n+1;i++)
      for(j=1;j<=m+1;j++)
        d[i][j]=false;
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
      {
        scanf("%d",&ch);
        if(ch==1)
          d[i][j]=true;
      }
    for(i=1;i<=q;i++)
    {
      ans=-1;
      scanf("%d%d%d%d%d%d",&ex[i],&ey[i],&sx[i],&sy[i],&tx[i],&ty[i]);
      if(sx[i]==tx[i]&&sy[i]==ty[i])
        ans=0;
      else
      {
        if(ex[i]==tx[i]&&ey[i]==ty[i])
        {
          if(((sx[i]==tx[i]+1||sx[i]==tx[i]-1)&&sy[i]==ty[i])||(sx[i]==tx[i]&&(sy[i]==ty[i]+1||sy[i]==ty[i]-1)))
            ans=1;
          if((sx[i]==tx[i]+1||sx[i]==tx[i]-1)&&(sy[i]==ty[i]+1||sy[i]==ty[i]-1))
            if(d[tx[i]][sy[i]]&&d[sx[i]][ty[i]])
              ans=5;
        }
        if(((ex[i]==tx[i]+1||ex[i]==tx[i]-1)&&ey[i]==ty[i])||(ex[i]==tx[i]&&(ey[i]==ty[i]+1||ey[i]==ty[i]-1)))
        {
          if(((sx[i]==tx[i]+1||sx[i]==tx[i]-1)&&sy[i]==ty[i])||(sx[i]==tx[i]&&(sy[i]==ty[i]+1||sy[i]==ty[i]-1)))
            ans=2;
          if((sx[i]==tx[i]+1||sx[i]==tx[i]-1)&&(sy[i]==ty[i]+1||sy[i]==ty[i]-1))
            if(d[tx[i]][sy[i]]&&d[sx[i]][ty[i]])
              ans=6;
        }
      }
      printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
