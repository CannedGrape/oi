#include<iostream>
#include<stdio.h>
using namespace std;
int n,k,m,s,t,h,add;
int c[101];
short got[101],go[101];
int map[101][101],p[101][101];
long long ans,tring;
void tryy(int k,int now)
{
     if (now==t) {if (ans>tring) ans=tring; return;}
     int i;
     for(i=1;i<=n;i++)
       if (go[i]==0)
         if (got[p[c[i]][c[now]]]==0&&map[now][i]>0)
         {
         tring=tring+map[now][i];
         go[i]=1;
         if (got[c[i]]==0) {add=1; got[c[i]]=1;} else add=0;
         
         tryy(k+1,i);
         tring=tring-map[now][i];
         if (add==1) got[c[i]]=0;
         go[i]=0;
         }
}
int main()
{
    freopen("culture.in","r",stdin);
    freopen("culture.out","w",stdout);
        cin>>n>>k>>m>>s>>t;
    int i,j,q[3];
    for(i=1;i<=n;i++)cin>>c[i];
    for(i=1;i<=k;i++)
      for(j=1;j<=k;j++)
       cin>>p[i][j];
    for(i=1;i<=m;i++)
      {
      cin>>q[0]>>q[1]>>q[2];
      if (map[q[0]][q[1]]==0||(map[q[0]][q[1]]>q[2]))
        {
      map[q[0]][q[1]]=q[2];
      map[q[1]][q[0]]=q[2];
        }
      }
    got[c[s]]=1;
    go[s]=1;
    ans=2147483647;
    if(p[t][c[s]]==1) {cout<<-1;return 0;}
    tring=0;
    tryy(1,s);
    
    if (h==0)cout<<ans; else cout<<-1;
    fclose(stdin);
    fclose(stdout);
 //   system("pause");
    return 0;
}
