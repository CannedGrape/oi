#include <iostream>
#include <stdio.h>
using namespace std;
int mod(long r,long s)
{
    bool fu=false;
    if(r<0) {fu=true; r=-r;}
    r=r%s;
    if(fu) r=-r;
    return r;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long n,p,lnum=0,lds=0,ldp=0,maxn=-100000001,lscore=0,maxc=-100000001;
    scanf("%ld%ld",&n,&p);
    for(int i=1;i<=n;i++)
    {
        int tmp=maxc+maxn;
        scanf("%ld",&lnum);
        lds=max(lds+lnum,lnum);
        maxn=max(maxn,lds);
        ldp=maxn;
        if(i==1) {lscore=maxn; maxc=max(maxc,lscore);}
        else
        {
            int maxs=tmp;
            lscore=maxs;
            maxc=max(maxc,lscore);
        }
    }
    printf("%d",mod(maxc,p));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
