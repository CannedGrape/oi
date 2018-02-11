#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int cap[1001][1001];
int line[10001][3];//[0]from,[1]to,[2]cap,last[101]
int n,m;
int q;
int min(int a,int b)
{
    if(a>=b)
      return b;
    else
     return a;
}
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int i,j,k;
    cin>>n>>m;
    int in1,in2;
    memset(cap,-1,sizeof(cap));
    int tot=0;
    for(i=1;i<=m;i++)
    { 
     cin>>in1>>in2;
     line[i][0]=in1;
     line[i][1]=in2;
     cin>>line[i][2];
    }
    for(i=1;i<=m;i++)
    {
      if(cap[line[i][0]][line[i][1]]==-1)
      {
        cap[line[i][0]][line[i][1]]=line[i][2];
        cap[line[i][1]][line[i][0]]=line[i][2];
      }
      else
        if(line[i][2]>cap[line[i][0]][line[i][1]])
        {
           cap[line[i][0]][line[i][1]]=line[i][2];
           cap[line[i][1]][line[i][0]]=line[i][2];
        }
    }
    for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
      for(k=1;k<=n;k++)
       if((i!=j)&&(j!=k))
        if((cap[i][j]<cap[i][k])&&(cap[i][j]<cap[k][j]))
        {
            cap[i][j]=min(cap[i][k],cap[k][j]);
            cap[j][i]=cap[i][j];        
        }
    cin>>q;
    for(i=1;i<=q;i++)
    {
        cin>>in1>>in2;
        cout<<cap[in1][in2]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
