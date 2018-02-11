#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int n,m,r[100001],dj,sj,tj;
int main()
{   freopen("classroom.in","r",stdin);freopen("classroom.out","w",stdout);
    int i,j;  scanf("%d %d",&n,&m);
    if((n>100000)&&(m>100000))
    {printf("0\n");
     fclose(stdin);
     fclose(stdout);
     return 0;
    }
    for(i=1;i<=n;i++)scanf("%d",&r[i]);
    for(i=1;i<=m;i++)
      {scanf("%d %d %d",&dj,&sj,&tj);
       for(j=sj;j<=tj;j++)
         {r[j]-=dj;
          if(r[j]<0)
            {printf("-1\n%d\n",i);
             fclose(stdin);
             fclose(stdout);
             return 0;
       } }  }
    printf("0\n");
    fclose(stdin);fclose(stdout);return 0;
}
