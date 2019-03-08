#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int n,tot=0;
int a[100001];
void init()
{
     int t,s,minn=2100000000;
     bool b;
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
       a[i]=0;
     for(int i=1;i<=n;i++)
       scanf("%d",&a[i]);
     a[n+1]=0;  
     for(int uuu=1;uuu<=10000000;uuu++)
     {
          b=0;   
          minn=2100000000;          
          for(int i=1;i<=1+n;i++)
          {
              if(a[i]!=0&&b==0)
              {
                  t=i;
                  b=1;                                    
              }     
              if(b==1&&a[i]!=0)
              {
                  if(minn>a[i])
                  minn=a[i];                                            
              }
              if(a[i]==0&&b==1)
              {                               
                  s=i-1;
                  break;            
              } 
          }
          b=1;
          for(int i=t;i<=s;i++)
            a[i]-=minn;
          tot+=minn;         
          for(int i=1;i<=n;i++)
            if(a[i]!=0)
              {b=0;break;}       
          if(b==1)
            break;            
     }
     printf("%d\n",tot);
}
int main()
{
       freopen("block.in","r",stdin);
       freopen("block.out","w",stdout);
       init();
       //system("pause");
       return 0;
}
                
                  
                       
                     
               
