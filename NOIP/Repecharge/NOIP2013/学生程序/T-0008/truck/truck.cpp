#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
int g[1002][1002],f[1002][1002],ans[1002],dis[1002][1002],b[1002],h[1002];
int n,m,q,t,w,x,y;
int Min(int a,int b){ return a<b?a:b; }
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; ++i){
        int z;
        scanf("%d%d%d",&x,&y,&z);
        g[x][++g[x][0]] =y;
        g[y][++g[y][0]] =x;
        f[y][x]=f[x][y] =z;
    }
   // printf("%d",f[0][0]);
    scanf("%d",&q);
    for (int z=1; z<=n; ++z)
    {
        for (int i=1; i<=n; ++i) b[i]=1,ans[i]=0;
        t=0; w=1; 
        h[1]=z; ans[z]=20000000; 
        do{
             x=h[++t]; b[x]=0;
             for (int i=1; i<=g[x][0]; ++i)
             {
                 y=g[x][i];
                 if (b[y] && (Min(ans[x],f[x][y])>ans[y]))
                 {
                         // printf("%d %d y=%d\n",ans[x],f[x][y],y);
                          ans[y]=Min(ans[x],f[x][y]);
                          h[++w]=y;
                 }
             }
        }while(t<w);
        for (int i=1; i<=n; ++i) dis[z][i]=ans[i];
        //printf("\n%d\n",z);
       // for (int i=1; i<=n; ++i) printf("%d  ",ans[i]);
    }
    for (int i=1; i<=q; ++i){
        scanf("%d%d",&x,&y);
        if (dis[x][y]!=0) printf("%d\n",dis[x][y]); 
        else printf("-1\n");   
    }
    fclose(stdin); fclose(stdout); 
   // system("pause");
}
