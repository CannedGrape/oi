#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
  freopen("treasure.in","r",stdin);
  freopen("treasure.out","w",stdout);
  int n,m;
  scanf("%d%d",&n,&m);
  int i,j,start,room,a[n+1][m],b[n+1][m],my;
  for(i=1;i<=n;i++)
  {
    for(j=0;j<=(m-1);j++)
    {
	  scanf("%d%d",&a[i][j],&b[i][j]);
    }
  }
  scanf("%d",&start);
  my=0;
  for(i=1;i<=n;i++)
  {
    room=b[i][start];
    my=(my+room)%20123;
    for(j=start;room!=0;j++)
    {
	  if(j>=m)
	  {
	    j=0;
      }
      if(a[i][j])
      {
	    room--;
	  }
    }
    start=j-1;
  }
  printf("%d",my);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
