#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<cstring>
using namespace std;
int n,p,coun=0;
int a[1001];
int r[1001][1001];
int high[1001];
bool byr[1001][1001];
void init()
{
     scanf("%d%d",&n,&p);
     for(int i=1;i<=p;i++)
     {
          scanf("%d",&a[i]);
          for(int j=1;j<=a[i];j++)
            scanf("%d",&r[i][j]);
     }
     for(int i=1;i<=p;i++)
       for(int j=1;j<=a[i];j++)
         byr[i][r[i][j]]=true;
     for(int i=1;i<=1000;i++)
       high[i]=1;     
     bool b=true;  
     while(b==true)
     {  
       b=false;      
       for(int i=1;i<=p;i++)
       {
           int minn=210000000,be=0,maxx=-2100000000;    
           for(int j=1;j<=a[i];j++)
             if(minn>high[r[i][j]])
               minn=high[r[i][j]];
           for(int j=r[i][1];j<=r[i][a[i]];j++)
              if(high[j]>=minn)   
            {be++;if(maxx<high[j]&&byr[i][j]==false)maxx=high[j];}          
           if(be>a[i])
            {for(int j=1;j<=a[i];j++)
             high[r[i][j]]=maxx+1;
             b=true;}
           coun++;  
       }
        if(coun>1001)
          b=false; 
     }
     int maxx=-21000000;
     for(int i=1;i<=n;i++)
      {if(high[i]>maxx)
       maxx=high[i];}
     printf("%d\n",maxx);
}
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    init();
    //system("pause");
    return 0;
}     
         
               
           
            
     
