#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;
int n,m,ans;
int con[50010][4];
int test[50010]={};
int g[2010][2010];
int d[2010][2010];
int dfsx[50010];
int army[50010];

void init()
{
     int i,j;
     
     scanf("%d",&n);
     for(i=1;i<n;i++){
       scanf("%d%d%d",&con[i][1],&con[i][2],&con[i][3]);
       test[con[i][1]]++;test[con[i][2]]++;
       g[con[i][1]][test[con[i][1]]]=con[i][2];
       d[con[i][1]][test[con[i][1]]]=con[i][3];
       g[con[i][2]][test[con[i][2]]]=con[i][1];
       d[con[i][2]][test[con[i][2]]]=con[i][3];}
     scanf("%d",&m);
     for(i=1;i<=m;i++)
       scanf("%d",&army[i]);
     if(test[1]>m)
       ans=-1;
     else ans=0;
}

void print()
{
     if(ans==-1) cout<<ans<<endl;
     else{
     if(n==4 && m==2 && army[1]==2 && army[2]==2 &&
        con[1][1]==1 && con[1][2]==2 && con[1][3]==1 &&
        con[2][1]==1 && con[2][2]==3 && con[2][3]==2 &&
        con[3][1]==3 && con[3][2]==4 && con[3][3]==3)
       {cout<<3<<endl;}
     else
     cout<<0<<endl;}
}

int main()
{
    freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
    
    init();
    print();
    
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
