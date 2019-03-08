#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
#define MXN 1000010
#define MM 20
long long zkw[(1<<MM)+5][2];//zkw[i][0]--start zkw[i][1]--end 
int n,m,num,mystart,myend,M=(1<<(MM-1))-1;
long long sum[MXN],a[MXN];
long long total=0;
void Init()
{
     scanf("%d%d",&n,&m);
     for (int i=1;i<=n;i++) {scanf("%lld",&a[i]);sum[i]=sum[i-1]+a[i];}
}
void change(int x,int aa)
{
     for (int i=((x+M)>>1);i;i>>=1)
       {
         zkw[i][aa]=zkw[i<<1][aa]+zkw[(i<<1)+1][aa];
       }
}
long long mycount(int l,int r,int aa)
{
     long long tot=0;
     for (l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1)
       {
        if(~l&1) tot+=zkw[l+1][aa];
        if(r&1) tot+=zkw[r-1][aa];
       }
     return tot;
}
void solve()
{
     long long cc,ww;
     for (int i=1;i<=m;i++)
       {
         scanf("%d%d%d",&num,&mystart,&myend);
         ww=(long long)num;
         zkw[mystart+M][0]+=ww;
         zkw[myend+M][1]+=ww;
         change(mystart,0);
         change(myend,1);
         total+=ww;
         cc=total;
         cc-=mycount(1,mystart-1,1);
         cc-=mycount(myend+1,n,0);
         if(cc>sum[myend]-sum[mystart-1]){
            printf("-1\n%d\n",i);
            return;
            }
       }
     printf("0\n");
}
void solve2()
{
     for (int i=1;i<=m;i++)
       {
         scanf("%d%d%d",&num,&mystart,&myend);
         for (int j=mystart;j<=myend;j++){
           a[j]-=(long long)num;
           if(a[j]<0){ printf("-1\n%d\n",i);return;}
           }
       }
     printf("0\n");
}
int main()
{
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    
    Init();
    if(n*m<=5000000) solve2();
    else solve();
    
    fclose(stdin);fclose(stdout);
    return 0;
}
