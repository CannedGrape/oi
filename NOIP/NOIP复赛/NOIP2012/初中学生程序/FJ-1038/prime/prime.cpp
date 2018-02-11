#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
      int 
          n,
          maxx=-1;

bool pand(int x)
 {
              int i;
              
              for (i=2;i<=x-1;i++)
                  if (x%i==0)
                     break;
              if (i<=x-1)
                 return 0;
               else
                   return 1;
 }
 
int main()
 {         
          freopen("prime.in","r",stdin);
          freopen("prime.out","w",stdout);
          
          int i;
                    
          cin>>n;
          for (i=1;i<=sqrt(n);i++){
              if (pand(i) && pand(n/i)){
                 if (i>n/i)
                    maxx=i;
                  else 
                       maxx=n/i;
                 break;
              }
          }
          
          cout<<maxx<<endl;
          
          fclose(stdin);
          fclose(stdout);
          //system("pause"); 
          return 0;
 }
