#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
long long num[100001]={};
long long ans;
char does[100001];
char st[100001];
int main()
{
    
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    int flag=0;
    int last=3,now;
    long long x=1,y=1;
    long long i;
    gets(st);
    for(i=0;i<=strlen(st)-1;i++)
     {/*输入数字*/
      if(st[i]>=48)
      {while(st[i]>=48) 
        {num[x]=num[x]*10+st[i]-48;
         i++;}
       num[x]%=10000;
       x++;}
      /*计算*/
      if(flag==1) 
        {if(now==1) ans=num[x-1]+num[x-2];
         if(now==2) ans=num[x-1]*num[x-2];
         num[x-1]=0;num[x-2]=0;
         x--;y--;num[x-1]=ans;flag=0;now=last;
        }
      
      /*输入符号*/
      if(st[i]=='+') {does[y]=st[i];y++;now=1;}
      if(st[i]=='*') {does[y]=st[i];y++;now=2;}
      /*判断是否进行计算*/
      if(last<now)flag=1;//要计算 
      else if(last==now) flag=2;
           else last=now;
       if(flag==2)
        {if(now==1) ans=num[x-1]+num[x-2];
         if(now==2) ans=num[x-1]*num[x-2];
         num[x-1]=0;num[x-2]=0;
         x--;y--;num[x-1]=ans;flag=0;now=last;
         }    

      }
   if(does[1]=='+') num[1]=num[1]+num[2];
   else num[1]=num[1]*num[2];
   
    cout<<num[1]%10000;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
