#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define MXN 100010
int n,a[MXN],q[MXN],tail,total;
void Init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++) scanf("%d",&a[i]);
}
void solve()
{
     int tmp;
     tail=1;
     for(int i=1;i<=n;i++)
       {tmp=-1;if(q[tail]>a[i]) tmp=q[tail];
         while(tail&&q[tail]>a[i]) tail--;
         q[++tail]=a[i];
         if(tmp>=0) total+=tmp-a[i];
       }
     total+=q[tail];
     printf("%d\n",total);
}
int main()
{
    freopen("block.in","r",stdin);freopen("block.out","w",stdout);
    Init();//
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}
