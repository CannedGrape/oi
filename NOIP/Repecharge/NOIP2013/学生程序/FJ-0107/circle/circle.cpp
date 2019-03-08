#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int n=0,m=0,k=0,x=0;
int i=0,j=0;



int main(){
long long tmp,rp;
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    cin>>n>>m>>k>>x;
    if(x==n){cout<<n;
             return 0;
            }
    
    if(n%(m-1)==0)
      {tmp=n;
      }
    else
      {tmp=(n)*(m-1);
      }
    rp=1;
    for(i=1;i<=k;i++)
      {rp=rp*10%tmp;
      }
    rp=rp%tmp;
    tmp=0;
    m=n-m;
    for(i=1;i<=rp;i++)
      {tmp=(tmp+m)%n;
      }
    if(tmp<x)
      {cout<<x-tmp;
      }
    else
      {if(tmp==x)
         {cout<<0;
         }
       else
         {cout<<n-(tmp-x)+1;
         }
       }
    return 0;
}
         
       
      
    
    
    
    
    
    
