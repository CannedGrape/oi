#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
 freopen("expr.in","r",stdin);
 freopen("expr.out","w",stdout);
    
 char list[1500000];
 long long ans=0,cir,length,p,temp,temp2;
 
 cin.getline(list,1500000);
 length=strlen(list);
 
 temp=temp2=0;
 list[length]='+';
 for(cir=0;cir<=length;cir++)
 {
  if(list[cir]!='+'&&list[cir]!='*')
    temp=temp*10+(list[cir]-'0');
  else if(list[cir]=='+')
  {
   ans+=temp;
   temp=0;    
  }
  else
  {
   p=cir+1;
   while(list[p]!='+'&&list[p]!='*')
   {
     temp2=temp2*10+(list[p]-'0');
     p++;
   }
   temp*=temp2;
   temp2=0;
   cir=p-1;    
  }                             
 }
 
 cout<<ans%10000;
 
 fclose(stdin);
 fclose(stdout);
 return 0;    
}
