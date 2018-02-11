#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,tryy,max;
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    cin>>a;
    c=0;
    b=0;
    max=0;
    d=a/2;
    for(b=2;b<=d;b++)
     {tryy=a%b;
      if(tryy==0)
       {for(c=2;c<=b-1;c++)
         {if(b%c==0)
           c=b;
         if(c==b-1)
           max=b;
         }
       }
     }
    cout<<max<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
