#include<cstring>
#include<cstdlib>
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  ifstream in("happy.in");
  ofstream out("happy.out");
  long ans[3][30001];
  int n,m,v,p;
  long money[26],value[26];
  long i,j;
  int max(int x,int y);
  in >> n >> m;
  memset(ans,0,sizeof(ans));
  for(i=1;i<=m;i++)
    {
      in >> v >> p;
      money[i]=v;
      value[i]=v*p;
    }
  for(i=0;i<=3;i++)
    ans[i][0]=0;
  for(i=0;i<=n;i++)
    ans[0][i]=0;
  for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
      if(j>=money[i])
        {if(i%2==1)
          ans[i%2][j]=max(ans[i%2-1][j-money[i]]+value[i],ans[i%2-1][j]);
        else ans[i%2][j]=max(ans[i%2+1][j-money[i]]+value[i],ans[i%2+1][j]);}
      else {
             if(i%2==1)
              ans[i%2][j]=ans[i%2-1][j];
             else ans[i%2][j]=ans[i%2+1][j];
           }
  out << ans[m%2][n] << endl;
  in.close();
  out.close();
  return 0;
}
int max(int x,int y)
{
  if(x>y)    return x;
  else return y;
}
