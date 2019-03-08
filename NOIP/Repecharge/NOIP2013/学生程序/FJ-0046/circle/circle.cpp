#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;
#define MXN 1000010
int n,m,K,x,record[MXN],tot,record2[MXN],tot2;
int pos[MXN];
void solve()
{//polya
     scanf("%d%d%d%d",&n,&m,&K,&x);
     int tmp=x,ff=0,rr;
     do
       {
         record[tot++]=tmp;
         tmp=(tmp+m)%n;
       }while(tmp!=x);
     //for(int i=0;i<tot;i++)printf("%d\n",record[i]);
     tmp=1;
     while(1)
       {
         tmp=(tmp*10)%tot;
         if(!pos[tmp]) {record2[++tot2]=tmp;pos[tmp]=tot2;}
         else {ff=pos[tmp]-1;break;}
       }
     //for(int i=1;i<=tot2;i++) printf("%d %d\n",i,record2[i]);
     rr=tot2-ff;
     //printf("%d %d\n",ff,rr);
     int aa=(K-ff)%rr+ff;
     if(aa==ff) aa+=rr;
     if(K<=ff)printf("%d\n",record[record2[K]]);
     else printf("%d\n",record[record2[aa]]);
}
int main()
{
    freopen("circle.in","r",stdin);freopen("circle.out","w",stdout);
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}
