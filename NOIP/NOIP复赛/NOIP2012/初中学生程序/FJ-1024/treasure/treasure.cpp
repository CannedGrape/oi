#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>
using namespace std;
int n,m;
int lc[1000001],bh[1000001];
int jl,total;
int cann[101];
void init()
{
     int i;
     cin>>n>>m;     
     for(i=1;i<=n*m;i++)
       scanf("%d%d",&lc[i],&bh[i]);
     cin>>jl;  
}
void tryy()
{
     int i,co,ssz,first,value,j;
     co=jl;
     value=0;
     for(i=1;i<=n;i++)
     {                      
       total=0;                                                 
       for(j=0;j<=m-1;j++)
       {
           if(lc[m*(i-1)+j+1]==1)             
           {
                total+=1;
                cann[total]=j;                
           }
           if(co==j)
             first=total;
       }
       ssz=bh[i]%total;  
       for(j=1;j<=ssz-1;j++)
       {
           first--;
           if(first<=0)first=total;
       }
       value+=bh[(i-1)*m+co+1];
       co=cann[total];                                             
     }
     cout<<value<<endl;
}
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    init();
    tryy();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
                    
