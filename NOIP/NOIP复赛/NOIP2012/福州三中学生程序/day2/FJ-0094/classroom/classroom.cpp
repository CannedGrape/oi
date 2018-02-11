#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int r[1000001];
int main()
{
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    int i,j,n,m,d,s,t;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      scanf("%d",&r[i]);
    for(i=1;i<=m;i++)
    {
      scanf("%d%d%d",&d,&s,&t);
      for(j=s;j<=t;j++)
      {
        r[j]=r[j]-d;
        if(r[j]<0)
        {
          printf("-1\n%d\n",i);
          fclose(stdin);
          fclose(stdout);
          return 0;
        }
      }
    }
    printf("0\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
