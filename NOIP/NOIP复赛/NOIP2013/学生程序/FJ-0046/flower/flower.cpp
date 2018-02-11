#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define MXN 100010
int n,a[MXN],record[MXN],tot,total,total2;
void Init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++) scanf("%d",&a[i]);
}
void solve()
{
     int K=0;
     if(n==1) {printf("1\n");return ;}
     for(int i=2;i<=n;i++)
       {
         if(a[i]>a[i-1]&&K!=1) {K=1;record[++tot]=1;}
         if(a[i]<a[i-1]&&K!=-1) {K=-1;record[++tot]=-1;}
       }
     //for(int i=1;i<=tot;i++) printf("%d\n",record[i]);
     for(int i=1;i<=tot;i++) if(record[i]==-1) total+=2;
     if(record[tot]==1) total++;
     for(int i=1;i<=tot;i++) if(record[i]==1) total2+=2;
     if(record[tot]==-1) total2++;
     total=max(total,total2);
     total=max(total,1);////
     printf("%d\n",total);
}
int main()
{
    freopen("flower.in","r",stdin);freopen("flower.out","w",stdout);
    Init();
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}
