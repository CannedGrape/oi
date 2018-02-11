#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int n;
int a[100001];
bool b;
int tot=1;
int the=0;
int bh;
void init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
       scanf("%d",&a[i]);
     if(a[1]<a[2])
       b=1;
     else
       b=0;
     bh=0;         
     if(a[n-1]>a[n])a[n+1]=2100000000;
     if(a[n-1]<a[n])a[n+1]=-2100000000;  
     for(int i=2;i<=n;i++)
     {             
          if(b==1)
          {
              bh++;    
              if(a[i-1]<a[i]&&a[i]>a[i+1])
              {
                     //printf("%d\n",the);                        
                  if(bh==1)
                  {tot+=1;the+=1;}
                  else
                  {
                    if(bh>1&&the%2==1)
                    {tot+=2;the+=2;}
                    else
                    {tot+=1;the+=1;}
                  }
                  b=0;bh=0;                  
              }           
          }
          else
          {
              bh++;    
              if(a[i-1]>a[i]&&a[i]<a[i+1])
              {
                  if(bh==1)
                  {tot+=1;the+=1;}
                  else
                  {
                    if(bh>1&&the%2==1)
                    {tot+=2;the+=2;}
                    else
                    {tot+=1;the+=1;}
                  }
                  b=1;bh=0;                  
              }   
          }
            
     }
     printf("%d\n",tot);                                    
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    init();
    //system("pause");
    return 0;
}
     
