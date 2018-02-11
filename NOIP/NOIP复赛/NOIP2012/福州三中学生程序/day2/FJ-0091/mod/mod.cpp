#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
long long a,b;
void solve()
{
     long long tt;
     tt=(a-1)/b;
     while(1)
       {
        if((b*tt+1)%a==0)
          {
           cout<<(b*tt+1)/a<<endl;
           break;
          }
        tt++;
       }
     return;
}
int main()
{
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    
    cin>>a>>b;
    solve();
    
    fclose(stdin);fclose(stdout);
    return 0;
}
