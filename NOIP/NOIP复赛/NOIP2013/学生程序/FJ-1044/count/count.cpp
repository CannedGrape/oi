#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int main()
{
    int n=0,x=0,s=0,i;
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    cin>>n>>x;
    if(n<10)
      {if(x==0) cout<<"0"<<endl;
       else
         {if(n>=x) cout<<"1"<<endl;
          else cout<<"0"<<endl;
         }
       fclose(stdin);
       fclose(stdout);
       //system("pause");
       return 0;
      }
    if(n<100)
      {if(x!=0) s++;
       for(i=10;i<=n;i++)
         {if(i/10==x) s++;
          if(i%10==x) s++;
         }
       cout<<s<<endl;
       fclose(stdin);
       fclose(stdout);
       //system("pause");
       return 0;
      }
    if(n<1000)
      {if(x!=0)s=20;
       else s=9;
       for(i=100;i<=n;i++)
         {if(i/100==x) s++;
          if(i%10==x) s++;
          if((i%100/10)==x) s++;
         }
       cout<<s<<endl;
       fclose(stdin);
       fclose(stdout);
       //system("pause");
       return 0;
      }
    if(n<10000)
      {if(x!=0)s=300;
       else s=189;
       for(i=1000;i<=n;i++)
         {if(i/1000==x) s++;
          if(i%10==x) s++;
          if((i%100/10)==x) s++;
          if((i%1000/100)==x) s++;
         }
       cout<<s<<endl;
       fclose(stdin);
       fclose(stdout);
       //system("pause");
       return 0;
      }
    if(n<100000)
      {if(x!=0) s=4000;
       else s=2889;
       for(i=10000;i<=n;i++)
         {if(i/10000==x) s++;
          if(i%10==x) s++;
          if((i%100/10)==x) s++;
          if((i%1000/100)==x) s++;
          if((i%10000/1000)==x) s++;
         }
       cout<<s<<endl;
       fclose(stdin);
       fclose(stdout);
       //system("pause");
       return 0;
      }
    if(n<1000000)
      {if(x!=0) s=50000;
       else s=38889;
       for(i=100000;i<=n;i++)
         {if(i/100000==x) s++;
          if(i%10==x) s++;
          if((i%100/10)==x) s++;
          if((i%1000/100)==x) s++;
          if((i%10000/1000)==x) s++;
          if((i%100000/10000)==x) s++;
         }
       cout<<s<<endl;
       fclose(stdin);
       fclose(stdout);
       //system("pause");
       return 0;
      }
    if(n==1000000)
      {if(x!=0) cout<<"600000"<<endl;
       else cout<<"488895"<<endl;
       fclose(stdin);
       fclose(stdout);
       //system("pause");
       return 0;
      }
}
