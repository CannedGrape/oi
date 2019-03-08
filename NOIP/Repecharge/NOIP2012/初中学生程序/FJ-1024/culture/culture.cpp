#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string.h>
#include<string>
#include<stdlib.h>
using namespace std;
int n,m,wh,q,z;
int awh[100001],gwh[100001];
int whct[1001][1001];
int roada[1001],roadb[1001],roadc[1001];
int map[101][101]; 
int now[101],cl[101];
bool zgm[11];
void init()
{
      int i,j;
      cin>>n>>wh>>m>>q>>z;
      for(i=1;i<=n;i++)
        cin>>awh[i];
      for(i=1;i<=wh;i++)
        for(j=1;j<=wh;j++)
          cin>>whct[i][j];
      for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
          map[i][j]=999999999;      
      for(i=1;i<=m;i++)
        {cin>>roada[i]>>roadb[i]>>roadc[i];map[roada[i]][roadb[i]]=roadc[i];map[roadb[i]][roada[i]]=roadc[i];}            
}
void dj()
{
    int i,j,k,l,value;
    for(k=1;k<=n;k++) 
      for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {    
            value=0; 
            zgm[awh[i]]=true;
            for(l=1;l<=wh;l++)
              if(zgm[l]==true)
                if(whct[l][awh[j]]==1)
                  value=99999999;
                 // cout<<map[i][j]<<" "<<i<<" "<<j<<endl;
            if(map[i][j]>map[i][k]+map[k][j]+value)
            {map[i][j]=map[i][k]+map[k][j];}
            else
            {zgm[awh[i]]=false;}
                
        }
    if(map[q][z]>=99999999)
      cout<<"-1"<<endl;
    else
      cout<<map[q][z]<<endl;                         
}
int main()           
{
      freopen("culture.in","r",stdin);
      freopen("culture.out","w",stdout);      
      init();
      dj();
      fclose(stdin);
      fclose(stdout);
      return 0;
}                        
