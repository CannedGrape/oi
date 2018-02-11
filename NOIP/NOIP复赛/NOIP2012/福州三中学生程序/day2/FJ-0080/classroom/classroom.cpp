#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <cstring>
#define MAM 1000010
#define MAN 1000010
using namespace std;
struct node
{
       int d,s,t;
}a[MAM];
int r[MAN];
int main()
{
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d",&r[i]);
    for (i=1;i<=m;i++) scanf("%d%d%d",&a[i].d,&a[i].s,&a[i].t);
    for (i=1;i<=m;i++)
      for (j=a[i].s;j<=a[i].t;j++) 
        {r[j]-=a[i].d;
         if (r[j]<0) 
           {printf("%d\n%d\n",-1,i);  
            fclose(stdin);
            fclose(stdout);
            return 0;
           }
        }
    printf("0\n");  
    fclose(stdin);
    fclose(stdout);
    return 0;
}
