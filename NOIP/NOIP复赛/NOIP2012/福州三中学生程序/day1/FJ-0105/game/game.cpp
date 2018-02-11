#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,a[10001][10001]={},b[10001]={},ans=0,t=0;
bool c[10001]={};
void cz()
{
     t++;
     int i,j,m=a[0][0];
     for(i=1;i<=n-1;i++)
       {for(j=1;j<=i;j++)
        m=m+a[j][0];}
        b[i]=m/a[i+1][1];
        if(t==1)
          ans=b[i];
        else
          {if(b[i]<ans)
          ans=b[i];}
}
void tryy(int s)
{
     int i;
     for(i=1;i<=n;i++)
       if(c[i]==0)
         {a[s][1]=a[i][1];
          a[s][2]=a[i][2];
          c[i]=1;
          if(s==n)
            cz();
          else
            tryy(s+1);
            //a[s][1]=0;
            //a[s][2]=0;
            c[i]=0;
            }   
}     
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int i,j,m=0;
    cin>>n;
    for(i=0;i<=n;i++)
      for(j=0;j<=1;j++)
        cin>>a[i][j]; 
    tryy(1);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
    
    
}
