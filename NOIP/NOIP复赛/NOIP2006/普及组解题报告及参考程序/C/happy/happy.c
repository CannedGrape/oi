#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  FILE *in=fopen("happy.in","r");
  FILE *out=fopen("happy.out","w");
  long ans[3][30001];
  int n,m,v,p;
  long money[26],value[26];
  long i,j;
  int max(int x,int y);
  fscanf(in,"%ld %ld",&n,&m);
  memset(ans,0,sizeof(ans));
  for(i=1;i<=m;i++)
    {
      fscanf(in,"%ld %ld",&v,&p);
      money[i]=v;
      value[i]=v*p;
    }
  fclose(in);
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
  fprintf(out,"%ld\n",ans[m%2][n]);
  fclose(out);
  return 0;
}
int max(int x,int y)
{
  if(x>y)    return x;
  else return y;
}
