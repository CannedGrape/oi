#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int N,K,M,S,T;
int A[200][200];
int  B[200][200];
bool pc[200][200];
int C[200];
int main()
{
  freopen("culture.in","r",stdin);
  freopen("culture.out","w",stdout);
   cin>>N>>K>>M>>S>>T;
   for(int i=1;i<=N;i++)
    { cin>>C[i];}
   for(int i=1;i<=K;i++)
    for(int j=1;j<=K;j++)
       cin>>pc[i][j];
    for(int i=1;i<=N;i++)   
      for(int j=1;j<=N;j++)
        B[i][j]=999999999;
   for(int i=1;i<=M;i++)
      { int ls1;int ls2;cin>>ls1>>ls2;B[ls1][ls2]=1; B[ls2][ls1]=1;}
   for(int k=1;k<=N;k++)
    for(int i=1;i<=N;i++)   
      for(int j=1;j<=N;j++)
          if(!pc[C[j]][C[i]] && !pc[C[j]][C[k]] &&!pc[C[k]][C[i]]){B[i][j]=min(B[i][j],B[i][k]+B[k][j]);}
  if(!pc[T][S])
   {cout<<B[S][T];}
   else {cout<<-1;}
  // system("pause");
  fclose(stdin);
  fclose(stdout);
   return 0;
}
