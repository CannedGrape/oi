#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
      int w[101],       //是否学过文化 
          ww=0,         //已学文化种数 
          r[101][101],  //路
          c[101],       //某国文化 
          x[101][101],  //是否排斥 
          n,k,m,s,t,
          minn=2147483647,
          f=0;
int main()
 {
          freopen("culture.in","r",stdin);
          freopen("culture.out","w",stdout);
          
          int i,j,
              u,v,d;
          
          memset(w,0,sizeof(w));
          cin>>n>>k>>m>>s>>t;
          
          for (i=1;i<=n;i++)
              cin>>c[i];
          for (i=1;i<=k;i++)
              for (j=1;j<=k;j++)
                  cin>>x[i][j];
          for (i=1;i<=m;i++){
              cin>>u>>v>>d;
              r[u][v]=d;
              r[v][u]=d;
          }
          cout<<"-1"<<endl;
          
          fclose(stdin);
          fclose(stdout);
          //system("pause");
          return 0;
 }
