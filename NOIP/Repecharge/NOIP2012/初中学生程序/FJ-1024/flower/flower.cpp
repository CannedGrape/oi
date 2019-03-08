#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string.h>
#include<string>
#include<stdlib.h>
using namespace std;
int n,m;
int fl[101];
int fj[101][101];
int value;
int total;
void init()
{
     int i;
     cin>>n>>m;
     for(i=1;i<=n;i++)
       cin>>fl[i];
}
void tryy(int t)
{
     int i;
     for(i=fl[t];i>=0;i--)
     {
          if(value+i<=m)
          {
             value+=i;
             if(t==n)
               {if(value==m)total=(total+1)%1000007;}
             else
                tryy(t+1);
             value-=i;            
          }        
     }
}
void print()
{
        cout<<total<<endl;
}
int main()           
{
      freopen("flower.in","r",stdin);
      freopen("flower.out","w",stdout);      
      init();
      tryy(1);
      print();
      fclose(stdin);
      fclose(stdout);
      return 0;
}                        
                        
                        
                                        
                          
                            
