#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int n,m,k,x;
int ten[5000001]; //---ten means 10^k the highest integer ---
int k2=1;
int a[101],c[101];//---a,c means m,x the highest integer --- 
int tot[5000001];     //tot means the total of the math (x+ten*m)%n   ---
void init()
{     
     scanf("%d%d%d%d",&n,&m,&k,&x);
     c[0]=2;c[1]=0;c[2]=1;          
     //---  fast to get 10^k  (80 score) ---
     ten[k+1]=1;ten[0]=k+1;
     //--- To get a high m and x---
     a[0]=0;
     while(m>0)
     {
         a[0]++;
         a[a[0]]=m%10;
         m/=10;      
     }    
     c[0]=0;
     while(x>0)
     {
         c[0]++;
         c[c[0]]=x%10;
         x/=10;      
     }
     //--- ten*m score (80 score) ---
     for(int i=ten[0];i<=ten[0]+a[0]-1;i++)
       ten[i]=a[i-ten[0]+1];
     ten[0]=ten[0]+a[0]-1;  
     //--- x+ten*m score (80 score) ---
     for(int i=1;i<=c[0];i++)
       ten[i]=c[i];
     //--- (x+ten*m)%n score (80 score) ---
     int mz=0;//mz means who mz>=n can mod a real numbers ---
     int zz=ten[0];//zz means the number can get somewhere ---
     while(zz>0)
     {
         mz=mz*10+ten[zz];
         zz--;
         if(mz>=n)
           mz%=n;
     }
     printf("%d\n",mz);   
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    init();
    return 0;
}
