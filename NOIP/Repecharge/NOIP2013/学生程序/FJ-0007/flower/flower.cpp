#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1001;
const int INF=0x7fffffff;
int G[maxn];
int M[maxn][maxn];
int K[maxn][maxn];
int n;
void init()
{
   scanf("%d",&n);
      for(int i=0;i<=n;i++){G[i]=INF;
      for(int j=0;j<=n;j++)
         {M[i][j]=INF;}}
   for(int i=1;i<=n;i++)
     scanf("%d",&G[i]);
     M[1][1]=G[1];
     K[1][1]=G[1];
   for(int i=2;i<=n;i++)
     for(int j=i;j>0;j--)
       {   
           if(M[i-1][j-1]>G[i] && M[i-1][j-1]>M[i-2][j-2])
              M[i][j]=G[i];
           if(K[i-1][j-1]<G[i] && K[i-1][j-1]<K[i-2][j-2])
              K[i][j]=G[i];
       }
   int i=n;
   int ansM=0,ansK=0;
    for(int i=0;i<=n;i++)
      if(M[n][i]!=INF)ansM++;if(K[n][i]!=INF)ansK++;
     cout<<max(ansM,ansK)<<"\n";
     // cout<<M[n][i]<<" ";
 //  while (M[n][i]==INF)i--;
 //  cout<<i;
}
int main()
{
   freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    init();
    //system("pause");
     fclose(stdin);
    fclose(stdout);       
    return 0;
}
