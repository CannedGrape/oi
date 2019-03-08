#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int n,p;
long long p2;
long long a[1000001];
int S[1000001];
long long lownum[1000001],sc[1000001];
long long maxsum=a[1];      
long long tot=a[1];
long long maxx=-2100000000; 
long long r;
void init()
{       
      scanf("%d%d",&n,&p);
      p2=p;      
      for(int i=1;i<=n;i++)
        scanf("%d",&S[i]);
       for(int i=1;i<=n;i++)
        a[i]=S[i];  
      lownum[1]=a[1];
         tot=a[1];      
     for(int i=2;i<=n;i++)
     {                
          if(tot<0)
          {
               if(maxsum<a[i])
                  maxsum=a[i];
               tot=a[i];                     
          }   
          else
          {
               if(tot+a[i]<=0)
                 tot=0;
               else
               {
                  tot+=a[i];
                  if(maxsum<tot)
                    maxsum=tot;                 
               }
          }
          lownum[i]=maxsum;
     }     
     sc[1]=lownum[1];    
     for(int i=2;i<=n;i++)
       {sc[i]=max(sc[i-1]+lownum[i-1],maxx);maxx=max(maxx,sc[i-1]+lownum[i-1]);}
     maxx=-2100000000;    
     for(int i=1;i<=n;i++)
     {  if(maxx<sc[i])
         maxx=sc[i];
     }
    
     if(maxx<0)
     {         
         r=-maxx;
         if(p2!=0)
         r%=p2;
         cout<<"-"<<r<<endl;         
     } 
     else
     {
         r=maxx;
         if(p2!=0)
         r%=p2;
         cout<<r<<endl;
     }
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    init();    
    return 0;
}            
       
