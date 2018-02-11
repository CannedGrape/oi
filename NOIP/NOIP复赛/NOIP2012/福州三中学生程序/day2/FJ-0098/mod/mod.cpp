#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

long long a,b,i,q;
bool d;
int main()
{
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    cin>>a>>b;
    
    while(d==0)
      {i++;
       if((b*i+1)%a==0)
         d=1;
      }
    /*i=b/a;
      while(d==0)
      {i++;
       if((a*i)%b==1)
         d=1;        
      }*/
    q=(i*b+1)/a;
    cout<<q;
    fclose(stdin);
    fclose(stdout);
    return 0;
    
    
}
