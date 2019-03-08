#include<cstdio>
using namespace std;
const int MAXN=100010;
int in[MAXN];
int f[MAXN][2];
int ans=0;
int max(int a,int b){return a>b?a:b;}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int n,i,j;
    scanf("%d",&n);
    f[0][1]=f[0][0]=0;
    for(i=1;i<=n;i++)
    {
       scanf("%d",&in[i]);
       for(j=0;j<i;j++)
       {
          if(in[j]<in[i])
          {
            f[i][1]=max(f[i][1],f[j][0]);               
          }
          if(in[j]>in[i])
          {
            f[i][0]=max(f[i][0],f[j][1]);               
          }
       } 
       f[i][1]++;
       f[i][0]++;
       ans=max(f[i][1],ans);
       ans=max(f[i][0],ans);
    }
    printf("%d\n",ans);
    return 0;
}
