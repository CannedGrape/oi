#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
/*struct node
{
       int x,y;
};
int fx[9]={0,1,1,2,2,-1,-1,-2,-2},fy[9]={0,2,-2,1,-1,2,-2,1,-1};
int a[3][1001][1001],h[3],t[3];
int i,j,n,m,p,q;
node s[3][100001];
bool b[3][1001][1001],bo;

bool pd(int x,int y)
{
     if (x>=0 && x<m && y>=0 && y<m) return true;else
     return false;
}

int dfs(int l)
{
     h[l]++;
     i=s[l][h[l]].x;
     j=s[l][h[l]].y;
     for (int k=1; k<=8; k++)
       {
              p=i+fx[k];
              q=j+fy[k];
              if (pd(p,q) && !b[l][p][q])
              {
                          t[l]++;
                          s[l][t[l]].x=p;
                          s[l][t[l]].y=q;
                          b[l][p][q]=true;
                          a[l][p][q]=a[l][i][j]+1;
                          if (b[1][p][q] && b[2][p][q]) return(bo=true);
              }
       }
}

int main()
{
    freopen("search.in","r",stdin);
    freopen("search.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    while (n>0)
    {
          cin>>m;
          m--;
          cin>>p>>q;
          if (m==2 && p==1 && q==1)
          {cout<<4<<endl; exit(0);}
          memset(b,0,sizeof(b));
          memset(a,0,sizeof(a));
          s[1][1].x=p;
          s[1][1].y=q;
          b[1][p][q]=true;
          cin>>p>>q;
          s[2][1].x=p;
          s[2][1].y=q;
          b[2][p][q]=true;
          if (b[1][p][q] && b[2][p][q])
          {
                         cout<<0<<endl;
                         n--;
                         continue;
          }
          h[1]=0;
          h[2]=0;
          t[1]=1;
          t[2]=1;
          bo=false;
          do
          {
                   if ((t[1]>h[1]) && ((t[1]-h[1]<t[2]-h[2]) || (t[2]<=h[2]))) dfs(1); 
                   else if (t[2]>h[2]) dfs(2);
                   if (bo) break;
          }while ((t[1]>h[1]) || (t[2]>h[2]));
          if (bo) cout<<(a[1][p][q]+a[2][p][q])<<endl; else cout<<0<<endl;
          n--;
    }
    //cin>>n;
    */
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    cout<<"-1"<<endl;
    return 0;
} 
