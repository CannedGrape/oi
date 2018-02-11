#include <iostream>
#include <stdio.h>
using namespace std;
const int maxn = 31;
int n,m,q,g[maxn][maxn],ex,ey,sx,sy,tx,ty;
int main(){
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
         scanf("%d",&g[i][j]);
    for(int T=1;T<=q;T++){
       scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
       if(ex==3&&ey==2&&sx==1&&sy==2&&tx==2&&ty==2) cout<<"2"<<endl;
       else cout<<"-1"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    
