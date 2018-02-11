#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[5000];
int ans=0,a1;
bool ch=0;
int main()
{
    long long int i;
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    cin.getline(a,5000);
    a1=strlen(a);
    long int o=0,p=1;
    for(i=0;i<a1;i++)
    {
                     

                         while(((a[i]!='*')&&(a[i]!='+'))&&((a[i]>='0')&&(a[i]<='9'))&&(i!=a1))
                         {o=o*10+(int)a[i]-'0';o%=10000;i++;}
                         if(ch)
                         {
                               if((a[i]=='*')||(a[i]=='+')){p*=o;o=0;}
                               if((a[i]=='+')||(i==a1)){ans+=p;p=1;ans%=10000;ch=0;}
                         }
                         else
                         {
                           if((a[i]=='+')||(i==a1)){ans+=o;o=0;ans%=10000;}
                           if(a[i]=='*'){ch=1;p*=o;o=0;} 
                         }
                         

    }
    cout<<ans%10000;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
                   
