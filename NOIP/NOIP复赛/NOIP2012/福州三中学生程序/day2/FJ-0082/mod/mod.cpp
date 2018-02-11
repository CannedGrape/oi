#include<iostream>
#include<cstdio>
using namespace std;
long long a,b,k=1,x;
int main()
{
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    
    scanf("%I64d%I64d",&a,&b);
    while(k)
      {if(a*k%b==1)
         {printf("%I64d\n",k);
          break;
          }
       else
         k+=(b-a*k%b)/a+1;
       }
    //system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
