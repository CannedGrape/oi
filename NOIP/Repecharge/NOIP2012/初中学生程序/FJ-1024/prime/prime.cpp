#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string>
using namespace std;
long long n,zs,ss;
double x;
long long zsb[100001];
long long zstf[100001];
void init()
{
     cin>>n;
     x=sqrt(n)+1;
     zs=int(x);
}
void fjzys()
{
     int i,j;
     zsb[1]=2;
     ss=1;     
     for(i=3;i<=zs;i++)
     {                       
         for(j=1;j<=ss;j++)
           if(i%zsb[j]==0)
             {zstf[i]=true;break;}
         if(zstf[i]==false)
           {ss++;zsb[ss]=i;}
     }  
}                          
void tryy()
{
     int i;
     for(i=1;i<=ss;i++)
     if(n%zsb[i]==0){cout<<n/zsb[i]<<endl;break;}
}
int main()
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    init();
    fjzys();
    tryy();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
                      
                      
     
     
