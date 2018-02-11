#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;
int n,m,b;
int r[1000][100][2];
int sum=0;
void zb(int f,int rm)
{
     int i,j,k;
     sum+=r[f][rm][1];
     sum=sum%20123;
     if(f==n) {cout<<sum;return;}
     i=0; j=0;
     while(i<=m-1)
       {if(r[f][i][0]==1) j++;
        i++;}
     k=r[f][rm][1]%j;
     if(k==0) k=j;
     i=0; j=rm-1;
     while(i<k)
       {j++;
        if(j==m) j=1;
        if(r[f][j][0]==1)
          i++;
        }
     zb(f+1,j);
}
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        cin>>r[i][j][0]>>r[i][j][1];
    cin>>b;
    zb(0,b);
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
     
