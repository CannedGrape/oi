#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<fstream>
using namespace std;
#define maxint (1<<29)
#define minint (-maxint)
#define MAXN 100005
int n,a[MAXN],ans=0;
int vis[10005]={};
inline void init()
{
       scanf("%d",&n);
       register int i;
       for(i=1;i<=n;i++)
         scanf("%d",&a[i]);
}
inline void solve()
{
       register int i,cnt,tot;
       bool flag=true;
       vis[a[1]]=cnt=tot=1;
       if(a[1]==0)
         vis[0]=cnt=tot=0;
       for(i=2;i<=n;i++){
           if(a[i]<a[i-1]){
               flag=false;
               if(vis[a[i]]==0&&a[i]!=0)
                 ++cnt;
               ++vis[a[i]];
           }
           if(a[i]>a[i-1]&&flag){
             if(vis[a[i]]==0&&a[i]!=0)
               ++cnt;
             ++vis[a[i]];
           }
           if(a[i]==a[i-1]&&a[i]!=0)
             ++vis[a[i]],++tot;
           if(a[i]>a[i-1]&&!flag){
               if(vis[a[i-1]]==tot){
                 if(a[i-1]!=0)
                   --cnt;
                 ans+=cnt;
                 memset(vis,0,sizeof(vis));
                 vis[a[i-1]]+=tot,++vis[a[i]];
                 cnt=(a[i-1]==0?1:2);
                 flag=true;
               }
               else{
                 memset(vis,0,sizeof(vis));
                 ans+=cnt;
                 vis[a[i]]=cnt=1;
                 flag=true;
               }
           }
           if(a[i]!=a[i-1])
             tot=1;
           //for(int j=0;j<=7;j++)cout<<vis[j]<<" ";cout<<endl;
       }
       ans+=cnt;
       printf("%d\n",ans);
}
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    init();
    solve();
    fclose(stdout);
    fclose(stdin);
    //system("pause");
    return 0;
}
/*
5 2 3 4 1 2

6 1 5 2 3 4 2

7 1 5 2 2 3 4 2

16
1 1 1 7 4 2 2 2 3 5 2 2 0 1 2 2

10
0 0 4 3 0 7 0 0 1 0

*/
