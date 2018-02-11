#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<algorithm>
using namespace std;



int main ()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    long long n,m,x=0,y=0,z=0,Ans=0;
    scanf("%I64d%I64d",&n,&m);
    for (int i=1; i<=n; ++i) 
      {
          z=i;
          while (z>0)
            {
                y=z%10;
                if (y==m) ++Ans;
                z=z/10;
            }
      }
    printf("%I64d",Ans);
    fclose(stdin); fclose(stdout);
}
